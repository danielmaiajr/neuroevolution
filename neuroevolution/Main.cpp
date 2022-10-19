#include <iostream>
#include <deque>
#include <raylib.h>

#include "Bird.h"
#include "Pipe.h"


int main()
{
    const int screenWidth = 800;
    const int screenHeight = 800;

    InitWindow(screenWidth, screenHeight, "NN");
    SetTargetFPS(60);

    Bird bird(screenWidth / 2, screenHeight / 2);
    std::deque<Pipe> pipes;

    Pipe pipe;

    int test = (int)GetTime();

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(BLACK);


        if (test != (int)GetTime())
        {
            Pipe newpipe;
            pipes.push_back(newpipe);
        }
        test = (int)GetTime();


        for (int i = 0; i < pipes.size(); i++)
        {
            if (pipes[i].hits(bird))
            {
                std::cout << "HITS" << "\n";
            }


            if (pipes[i].offscreen())
            {
                pipes.erase(pipes.begin() + i);
            }

            pipes[i].update();
            pipes[i].show();
        }


        if (pipes.size() > 0) 
            bird.think(pipes);
        bird.update();
        bird.show();


        EndDrawing();



        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

}