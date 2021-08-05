/*
 *%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 *%									   %
 *%	Copyright (C) 1991, by WATCOM Systems Inc. All rights reserved.    %
 *%									   %
 *%     Permission is granted to anyone to use this example program for	   %
 *%     any purpose on any computer system, subject to the following	   %
 *%	restrictions:							   %
 *%									   %
 *%     1. This example is provided on an "as is" basis, without warranty. %
 *%	   You indemnify, hold harmless and defend WATCOM from and against %
 *%	   any claims or lawsuits, including attorney's, that arise or	   %
 *%	   result from the use or distribution of this example, or any     %
 *%	   modification thereof.					   %
 *%									   %
 *%     2. You may not remove, alter or suppress this notice from this	   %
 *%        example program or any modification thereof.			   %
 *%									   %
 *%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 *
 * WGLOBAL.C
 *
 * global variables for WATZEE 
 *
 */

#include <windows.h>

#define MAX_PLAYERS              5
#define PLAYER_DATA_ELEMENTS    19


typedef struct die_info {
    short    value;
    BOOL     is_checked;
} die_info;

typedef struct dice_info {
    short   sum;
    short   count[7];
    BOOL    got_three_kind;
    BOOL    got_four_kind;
    BOOL    got_full_house; 
    BOOL    got_small_straight;
    BOOL    got_large_straight;
    BOOL    got_watzee;
} dice_info;


short       NumberOfPlayers;
short       Player[ MAX_PLAYERS ] [ PLAYER_DATA_ELEMENTS ];
char        PlayerName[ MAX_PLAYERS ][ 4 ];
die_info    Dice[ 5 ];
dice_info   DiceInfo;
BOOL        GotTimer;
BOOL        PCTurn;
BOOL        PlayingGameYet;
BOOL        DieCheckMeansRoll;
BOOL        ResetDieChecks;
short       CharWidth;
short       CharHeight;
short       SysHeight;
short       CurrentPlayer;
short       CurrentTurn;
short       CurrentRoll;
short       LastScoreSelection;
LOGFONT     SmallNormalFont;
LOGFONT     SmallBoldFont;
