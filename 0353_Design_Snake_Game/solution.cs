using System;
using System.Collections.Generic;

public class SnakeGame
{
    public class Position
    {
        public int X;
        public int Y;
    }

    private int width, height, score;
    private List<Position> food;

    private List<Position> body = new List<Position>();


    public SnakeGame(int width, int height, List<Position> food)
    {
        this.width = width;
        this.height = height;
        this.food = food;
        score = 0;
        body.Add(new Position { X = 0, Y = 0 });
    }

    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    public int Move(string direction)
    {
        // head is the fist pos
        Position head = body[0];
        Position tail = body[body.Count - 1];

        body.RemoveAt(body.Count - 1);   //Remove the tail

        if (direction == "U") 
            head.Y--;
        else if (direction == "L") 
            head.X --;
        else if (direction == "R")
            head.X++;
        else if (direction == "D") 
            head.Y++;


        if (this.TouchBody(head) || this.OutOfRange(head))
        {
            return -1;
        }
        body.Insert(0, head);      // Add new head

        if (food.Count!=0 && head.X == food[0].X && head.Y == food[0].Y)   
        {
            // If eat food, add new tail
            food.RemoveAt(0);
            body.Add(tail);
            ++score;
        }
        return score;
    }

    private bool TouchBody(Position head)
    {
        foreach( Position pos in body)
        {
            if(pos.X == head.X && pos.Y == head.Y)
                return true;
        }
        return false;
    }
    private bool OutOfRange(Position pos)
    {
        return pos.X < 0 || pos.X >= this.width|| pos.Y < 0 || pos.Y >= this.height;
    }

};

// http://www.programcreek.com/2014/08/leetcode-design-snake-game-java/