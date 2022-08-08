/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byahn <byahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 20:25:40 by byahn             #+#    #+#             */
/*   Updated: 2022/08/07 20:25:42 by byahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate(t_game *game, double rot)
{
	double	tmp;

	tmp = game->player.dir.x;
	game->player.dir.x = game->player.dir.x * cos(rot)
		- game->player.dir.y * sin(rot);
	game->player.dir.y = game->player.dir.y * cos(rot)
		+ tmp * sin(rot);
	tmp = game->player.plane.x;
	game->player.plane.x = game->player.plane.x * cos(rot)
		- game->player.plane.y * sin(rot);
	game->player.plane.y = game->player.plane.y * cos(rot)
		+ tmp * sin(rot);
}

void	move_wasd(t_coordinate_d *dest, t_game *game)
{
	t_player	*player;

	player = &game->player;
	if (game->key_state.w == true)
	{
		dest->x += player->dir.x * player->move_speed;
		dest->y += player->dir.y * player->move_speed;
	}
	if (game->key_state.s == true)
	{
		dest->x -= player->dir.x * player->move_speed;
		dest->y -= player->dir.y * player->move_speed;
	}
	if (game->key_state.a == true)
	{
		dest->x -= player->plane.x * player->move_speed;
		dest->y -= player->plane.y * player->move_speed;
	}
	if (game->key_state.d == true)
	{
		dest->x += player->plane.x * player->move_speed;
		dest->y += player->plane.y * player->move_speed;
	}
}

void	rotate_lr(t_game *game)
{
	if (game->key_state.l == true)
		rotate(game, game->player.rot_speed);
	if (game->key_state.r == true)
		rotate(game, -(game->player.rot_speed));
}

void	moving(t_game *game)
{
	t_coordinate_d	dest;

	dest.x = game->player.pos.x;
	dest.y = game->player.pos.y;
	move_wasd(&dest, game);
	rotate_lr(game);
	if (game->map.map[(int)(dest.x)][(int)(game->player.pos.y)] != '1')
		game->player.pos.x = dest.x;
	if (game->map.map[(int)(game->player.pos.x)][(int)(dest.y)] != '1')
		game->player.pos.y = dest.y;
}
