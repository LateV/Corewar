/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_map_handler2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkhilenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 15:50:29 by rkhilenk          #+#    #+#             */
/*   Updated: 2018/09/21 15:50:31 by rkhilenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		win_art_winner(t_cor *cor)
{
	int x;
	int y;

	x = 10;
	y = 70;
	wattron(cor->vizu->win1, COLOR_PAIR((cor->winner->num) * (-1)));
	mvwprintw(cor->vizu->win1, x++, y, "%s",
	"              (           )        )             (     ");
	mvwprintw(cor->vizu->win1, x++, y, "%s",
	"  (  (        )\\ )     ( /(     ( /(             )\\ )  ");
	mvwprintw(cor->vizu->win1, x++, y, "%s",
	"  )\\))(   '  (()/(     )\\())    )\\())    (      (()/(  ");
	mvwprintw(cor->vizu->win1, x++, y, "%s",
	" ((_)()\\ )    /(_))   ((_)\\    ((_)\\     )\\      /(_)) ");
	mvwprintw(cor->vizu->win1, x++, y, "%s",
	" _(())\\_)()  (_))      _((_)    _((_)   ((_)    (_))   ");
	mvwprintw(cor->vizu->win1, x++, y, "%s",
	" \\ \\((_)/ /  |_ _|    | \\| |   | \\| |   | __|   | _ \\  ");
	mvwprintw(cor->vizu->win1, x++, y, "%s",
	"  \\ \\/\\/ /    | |     | .` |   | .` |   | _|    |   /  ");
	mvwprintw(cor->vizu->win1, x++, y, "%s",
	"   \\_/\\_/    |___|    |_|\\_|   |_|\\_|   |___|   |_|_\\  ");
	wattroff(cor->vizu->win1, COLOR_PAIR((cor->winner->num) * (-1)));
}

static void	win_art_sword4(t_cor *cor, int y, int x)
{
	mvwprintw(cor->vizu->win1, x++, y, "%s",
	"|                \\  U  /                |");
	mvwprintw(cor->vizu->win1, x++, y, "%s",
	"|                 \\   /                 |");
	mvwprintw(cor->vizu->win1, x++, y, "%s",
	"|                  \\ /                  |");
	mvwprintw(cor->vizu->win1, x++, y, "%s",
	"|                   V                   |");
	mvwprintw(cor->vizu->win1, x++, y, "%s",
	"|                                       |");
	mvwprintw(cor->vizu->win1, x++, y, "%s",
	"-----------------------------------------");
	wattroff(cor->vizu->win1, COLOR_PAIR((cor->winner->num) * (-1) + 8));
}

static void	win_art_sword3(t_cor *cor, int y, int x)
{
	mvwprintw(cor->vizu->win1, x++, y, "%s",
	"|     \\    \\ \\     |||     / /    /     |");
	mvwprintw(cor->vizu->win1, x++, y, "%s",
	"|      \\    \\ \\    |||    / /    /      |");
	mvwprintw(cor->vizu->win1, x++, y, "%s",
	"|       \\    \\ \\   |||   / /    /       |");
	mvwprintw(cor->vizu->win1, x++, y, "%s",
	"|        \\    \\ \\  |||  / /    /        |");
	mvwprintw(cor->vizu->win1, x++, y, "%s",
	"|         \\    \\ \\ ||| / /    /         |");
	mvwprintw(cor->vizu->win1, x++, y, "%s",
	"|          \\    \\ \\|||/ /    /          |");
	mvwprintw(cor->vizu->win1, x++, y, "%s",
	"|           \\  (========)   /           |");
	mvwprintw(cor->vizu->win1, x++, y, "%s",
	"|            \\     |\\|     /            |");
	mvwprintw(cor->vizu->win1, x++, y, "%s",
	"|             \\    |\\|    /             |");
	mvwprintw(cor->vizu->win1, x++, y, "%s",
	"|              \\   |\\|   /              |");
	mvwprintw(cor->vizu->win1, x++, y, "%s",
	"|               \\  (I)  /               |");
	win_art_sword4(cor, y, x);
}

static void	win_art_sword2(t_cor *cor, int y, int x)
{
	mvwprintw(cor->vizu->win1, x++, y, "%s",
	"|             / /  |||  \\ \\             |");
	mvwprintw(cor->vizu->win1, x++, y, "%s",
	"|            | |   |||   | |            |");
	mvwprintw(cor->vizu->win1, x++, y, "%s",
	"|            | |   |||   | |            |");
	mvwprintw(cor->vizu->win1, x++, y, "%s",
	"|            / |   |||   | \\            |");
	mvwprintw(cor->vizu->win1, x++, y, "%s",
	"|    ___    |  /   |||   \\  |    ___    |");
	mvwprintw(cor->vizu->win1, x++, y, "%s",
	"|    \\  \\__ | |    |||    | | __/  /    |");
	mvwprintw(cor->vizu->win1, x++, y, "%s",
	"|\\    \\  _ `' |    |||    | `' _  /    /|");
	mvwprintw(cor->vizu->win1, x++, y, "%s",
	"| \\    \\ \\`_  |    |||    |  _'/ /    / |");
	mvwprintw(cor->vizu->win1, x++, y, "%s",
	"|  \\    \\ \\ `.'    |||    `.' / /    /  |");
	mvwprintw(cor->vizu->win1, x++, y, "%s",
	"|   \\    \\ \\       |||       / /    /   |");
	mvwprintw(cor->vizu->win1, x++, y, "%s",
	"|    \\    \\ \\      |||      / /    /    |");
	win_art_sword3(cor, y, x);
}

void		win_art_sword(t_cor *cor, int y)
{
	int x;

	x = 10;
	wattron(cor->vizu->win1, COLOR_PAIR((cor->winner->num) * (-1) + 8));
	mvwprintw(cor->vizu->win1, x++, y, "%s",
	"-----------------------------------------");
	mvwprintw(cor->vizu->win1, x++, y, "%s",
	"|                   ^                   |");
	mvwprintw(cor->vizu->win1, x++, y, "%s",
	"|                  / \\                  |");
	mvwprintw(cor->vizu->win1, x++, y, "%s",
	"|                 / ^ \\                 |");
	mvwprintw(cor->vizu->win1, x++, y, "%s",
	"|                / / \\ \\                |");
	mvwprintw(cor->vizu->win1, x++, y, "%s",
	"|               / / ^ \\ \\               |");
	mvwprintw(cor->vizu->win1, x++, y, "%s",
	"|              / / / \\ \\ \\              |");
	mvwprintw(cor->vizu->win1, x++, y, "%s",
	"|             | |  \\ /  | |             |");
	mvwprintw(cor->vizu->win1, x++, y, "%s",
	"|             | |  |V|  | |             |");
	win_art_sword2(cor, y, x);
}
