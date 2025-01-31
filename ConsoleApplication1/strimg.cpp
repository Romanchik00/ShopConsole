﻿#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <conio.h>

#define stuff "stuff.save"
#define product "product.save"

using namespace std;

const char* sattr[]{ u8"Имя",u8"Фамилия",u8"Отцество",u8"Пол",u8"Должность",u8"Статус" };
const char* pattr[]{ u8"Имя",u8"Цена продажи",u8"Цена закупки",u8"Количество на складе",u8"Количество в магазине",u8"Артикул" };


void TitlePage();

extern const char man[]{
"....................................\0\
.............@@@@@@@@...............\0\
...........@@@@@@@@@@@@.............\0\
..........@@@@@@@@@@@@@@............\0\
..........@@@@@@@@@@@@@@............\0\
.........@@@@@@@@@@@@@@@@...........\0\
.........@@@@@@@@@@@@@@@@...........\0\
..........@@@@@@@@@@@@@@............\0\
...........@@@@@@@@@@@@.............\0\
...........@@@@@@@@@@@..............\0\
............@@@@@@@@@@..............\0\
...........@@@@@@@@@@@@.............\0\
.......@@@@@@@@@@@@@@@@@@@@.........\0\
...@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%...\0\
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\0\
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" },
female[]{
"....................................\0\
............-@@@@@@@@@=.............\0\
...........#@@@@@@@@@@@%:...........\0\
..........#@@@@@@@@@@@@@#...........\0\
.........=@@@@@@@@@@@@@@@%..........\0\
.........#@@@@@@@@@@@@@@@@..........\0\
.........=@@@@@@@@@@@@@@@@-.........\0\
.........+@@@@@@@@@@@@@@@@*.........\0\
..........:@@@@@@@@@@@@@@@=.........\0\
...........-@@@@@@@@@@+=--=.........\0\
...........-@#=@@@@@@@%-............\0\
..............*@@@@@@@@+............\0\
.....-*####%@@@@@@@@@@@@@@+:........\0\
...:%@@@@@@@@@@@@@@@@@@@@@@@@@@@-...\0\
...*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-..\0\
...@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@.." },
beer[]{
"#...............:%%#*..............#\0\
#...............:%%##..............#\0\
#...............:%%+*..............#\0\
#...............:%%=#..............#\0\
#...............+%%+#:.............#\0\
#...............%#:................#\0\
#..............:*+=:-+.............#\0\
#..............+%%%*=%:............#\0\
#.............:%%%%#=%+............#\0\
#.............-%@%%%#%%............#\0\
#.............=@%:::-%#............#\0\
#.............=@*-+=.#%............#\0\
#.............-+#*#*+==............#\0\
#.............:##+..=-=............#\0\
#.............:%*-==:*=............#\0\
#..............:%@%%%*.............#" },
wine[]{
"#..................................#\0\
#.......................#@#........#\0\
#.......................*@*........#\0\
#.......................*%*........#\0\
#.......................#@%........#\0\
#.......... ..... ....+-@@@#:......#\0\
#..........#-----#....==@@@#*......#\0\
#........#........#...|:-=++|......#\0\
#........#.-%%%%%+#...|.:-=+|......#\0\
#........#.=#%%%%-#...|.:-=+|......#\0\
#........#..=##*:.#...|.:-=+|......#\0\
#...........#:-#......++@@@#*......#\0\
#...........#.:#......++@@@#*......#\0\
#...........#.:#......*+@@@#*......#\0\
#..........#..:.#.....*+@@@#*......#\0\
#........#..-----.#...+%@@@%-......#" },
apple[]{
"#..................................#\0\
#................:**#***-..........#\0\
#...........:...+*++**+............#\0\
#............=.::--:...............#\0\
#..........:=*%###%#*++-...........#\0\
#.......=*#######%%%%%%##*:........#\0\
#......+*++***##%%%%%%%%%%#:.......#\0\
#.....=*+==--=*#%%%%%%%%%%%*.......#\0\
#.....+#*+=-:=#%%%%#%%%%%%##.......#\0\
#.....+*******##%%%##%%%#%##.......#\0\
#.....=******#############%+.....  #\0\
#......+**######%#%%%%%%###........#\0\
#......:*######%%%%%%%%%%#.........#\0\
#........+#####%%%%%%%%%+..........#\0\
#..........+###%%%%%%%*............#\0\
#.............::-:::...............#" },
orange[]{
"#..................................#\0\
#.......#.::.-=**+===--:...........#\0\
#.....#.-:.-+****######+--.........#\0\
#...#.:-:.-*#****#######**+:.......#\0\
#..#.--:.=##******##*******-.......#\0\
#.#.:--.:##*****##****#****#-......#\0\
#.#.---.:#*******+-::=******=:.....#\0\
#.#.---::*++****#*-::+#******:.....#\0\
#.#.---:.-******************+:.....#\0\
#.#.:---::#*****************-......#\0\
#..#.----::+************++*-:......#\0\
#...#.:==-:..=#***********-:.......#\0\
#.....#.===-:.-+*++**+*=::.........#\0\
#.......#:-=+=-::..:..::...........#\0\
#.........#:--======--:............#\0\
#..................................#" };
extern const char banana[]{
"....%%..............................\0\
...#+++#............................\0\
..##***#............................\0\
..@=-#-+#...........................\0\
..#== *--+#*@.......................\0\
..+--%==-----+--=#@@+._.+@%*---:::=%\0\
%+--:-+=---:::-:=--::::::::---::::-.\0\
*---::--+----:::+--:-====--------+.#\0\
*----:::--=-------::::--:::---------\0\
.*----::::-:+---------------------::\0\
..*-----:::::-:--+---::::::::==---+*\0\
....+-=------:::::::::::::----**%...\0\
......*-==------------------+%......\0\
.........#==----------=-=+*.........\0\
..............%###****%.............\0\
...................................." },
pear[]{
"#-------------------=+-------------#\0\
#-----------------==---------------#\0\
#-----------------=----------------#\0\
#--------------=+++==--------------#\0\
#------------==+++===--------------#\0\
#-----------==+++==+==-------------#\0\
#----------===++======-------------#\0\
#--------===+++++=====-------------#\0\
#-------====++++=======------------#\0\
#------++++++++========------------#\0\
#------=+++*+++++==-===------------#\0\
#------=++++++++=====-+------------#\0\
#-------=+++++======-+-------------#\0\
#--------============--------------#\0\
#----------==++++===---------------#\0\
#----------------------------------#" },
god[]{
"....................................\0\
..............-#*#-.................\0\
...............-#%..................\0\
................%#..................\0\
..........*%#+%##%*##*%*:...........\0\
........###++#**--%+*%*%##..........\0\
.......###++%+*%-++#*##*%#%.........\0\
.......%*%####%%#%%%%#%###%:........\0\
.......##+=============+###.........\0\
........#==============+*#..........\0\
........*==============++*..........\0\
........-*============++#=..........\0\
.........++==========++*+...........\0\
..........+#========++#+............\0\
............+%*====*%*..............\0\
...............%==%................." },
box[]{
"###------------------------------###\0\
#----------------------------------#\0\
#----------------------------------#\0\
#----------------------------------#\0\
#----------------?-----------------#\0\
#----------------------------------#\0\
#----------------------------------#\0\
#---------?------x------?----------#\0\
#----------------------------------#\0\
#----------------------------------#\0\
#----------------?-----------------#\0\
#----------------------------------#\0\
#----------------------------------#\0\
#----------------------------------#\0\
#----------------------------------#\0\
###------------------------------###" },
test[]{
"###------------------------------###\n\
#----------------------------------#\n\
#----------------+-----------------#\n\
#----------------------------------#\n\
#------------+--------+------------#\n\
#----------------------------------#\n\
#----------------?-----------------#\n\
#--------+----?--x--?-----+--------#\n\
#----------------?-----------------#\n\
#----------------------------------#\n\
#-----------+----------+-----------#\n\
#----------------------------------#\n\
#----------------+-----------------#\n\
#----------------------------------#\n\
#----------------------------------#\n\
###------------------------------###" };


void TitlePage() {
	printf(u8"\
▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n\
▒▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒\n\
▒▒░░╔══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗░░▒▒\n\
▒▒░░║▀  ▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲  ▀║░░▒▒\n\
▒▒░░║                                                                                                                              ║░░▒▒\n\
▒▒░░║                                                                                                                              ║░░▒▒\n\
▒▒░░║                                                                                                                              ║░░▒▒\n\
▒▒░░║                                      __    __    __  ___       ___  ____     __    __                                        ║░░▒▒\n\
▒▒░░║                                      \\∙\\  /∙∙\\  /∙/ │‾‾‾ │    ╱╱‾‾ ╱╱••╲╲   /∙∙\\  /∙∙\\                                       ║░░▒▒\n\
▒▒░░║                                       \033[95m\\∙\\/∙/\\∙\\/∙/  │═══ │    █ ✶  █    █  /∙/\\∙\\/∙/\\∙\\\033[0m                                      ║░░▒▒\n\
▒▒░░║                                        \\∙∙/  \\∙∙/   │___ │___ ╲╲__ ╲╲••╱╱ /∙/  \\∙∙/  \\∙\\                                     ║░░▒▒\n\
▒▒░░║                                         ‾‾    ‾‾     ‾‾‾  ‾‾‾  ‾‾‾  ‾‾‾‾  ‾‾    ‾‾    ‾‾                                     ║░░▒▒\n\
▒▒░░║                                                             ∙IN∙                                                             ║░░▒▒\n\
▒▒░░║                                                                                                                              ║░░▒▒\n\
▒▒░░║                                                         ˹          ˺                                                         ║░░▒▒\n\
▒▒░░║                                                        « \033[92mШЕСТЁРОЧКА\033[0m »                                                        ║░░▒▒\n\
▒▒░░║                                                         ˻          ˼                                                         ║░░▒▒\n\
▒▒░░║                                                                                                                              ║░░▒▒\n\
▒▒░░║                                                                                                                              ║░░▒▒\n\
▒▒░░║                                                       \033[33;21m_______________\033[0m                                                        ║░░▒▒\n\
▒▒░░║                                                    \033[33;21m∙◊╳\033[43;21;30m PRESS × ENTER \033[0m \033[33;21m╳◊∙\033[0m                                                    ║░░▒▒\n\
▒▒░░║                                                       \033[33;21m‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾\033[0m                                                        ║░░▒▒\n\
▒▒░░║                                                                                                                              ║░░▒▒\n\
▒▒░░║                                                              ♦                                                               ║░░▒▒\n\
▒▒░░║                                                        ╔═════╬═════╗                                                         ║░░▒▒\n\
▒▒░░║                                                       ┌╜     ▲     ╙┐                                                        ║░░▒▒\n\
▒▒░░║                                                       └╖    / \\    ╓┘                                                        ║░░▒▒\n\
▒▒░░║                                                        ║  ▀/ | \\▀  ║                                                         ║░░▒▒\n\
▒▒░░║                                                        ║  /  ▲  \\  ║                                                         ║░░▒▒\n\
▒▒░░║                                                       ♦╬ ◄   ☼   ► ╬♦                                                        ║░░▒▒\n\
▒▒░░║                                                        ║  \\  ▼  /  ║                                                         ║░░▒▒\n\
▒▒░░║                                                        ║  ▄\\ | /▄  ║                                                         ║░░▒▒\n\
▒▒░░║                                                       ┌╜    \\ /    ╙┐                                                        ║░░▒▒\n\
▒▒░░║                                                       └╖     ▼     ╓┘                                                        ║░░▒▒\n\
▒▒░░║                                                        ╚═════╬═════╝                                                         ║░░▒▒\n\
▒▒░░║                                                              ♦                                                               ║░░▒▒\n\
▒▒░░║▄  ▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲▼▲  ▄║░░▒▒\n\
▒▒░░╚══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝░░▒▒\n\
▒▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒\n\
▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n");
}