/*
options.c
All game options
*/

#include <stdlib.h>
#include <SDL2/SDL.h>

#include "constants.h"
#include "globals.h"

// Creates the file name
void getFile(char fileName[20], int i)
{
  char path[20], numstr[2];

  strcpy(path, "levels/lvl");
  strcpy(fileName, path);
  sprintf(numstr, "%d", i);
  strcat(fileName, numstr);
  strcat(fileName, ".txt");
}

// Selects the appropriate action, depending on the GAME_MODE
void option(SDL_Renderer *renderer)
{
    char fileName[20];

    switch(GAME_MODE)
    {
        case PLAY:
          printf("Startig new game.\n");

          // Zero the score
          MOVES = 0;
          BOOKS = 0;

          // Loop through the levels
          for (int i = 1; i <= ALL_LEVELS; i++)
          {
              // Get file name
              getFile(fileName, i);
            //if(!game(renderer, fileName, option)) break;
          }

          break;

        case CONTINUE:
            printf("Loading saved game.\n");
            strcpy(fileName, "continue.txt");
            //if(!game(renderer, fileName, option)) break;
            LVL_NUM++;
            for (int i = LVL_NUM; i <= ALL_LEVELS; i++)
            {
                GAME_MODE = PLAY;

                // Get file name
                getFile(fileName, i);
                //if(!game(renderer, fileName, option)) break;
            }

            break;

        case EDIT:
            printf("Edit custom level.\n");
            strcpy(fileName, "custom.txt");
            //editor(renderer);
            break;

        case CUSTOM:
            printf("Play custom level.\n");
            strcpy(fileName, "custom.txt");
            //if(!game(renderer, fileName, option)) break;
            break;
    }
}
