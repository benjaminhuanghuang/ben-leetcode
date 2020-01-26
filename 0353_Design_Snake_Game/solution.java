package cn.huang.leetcode;
/*
 353. Design Snake Game

Design a Snake game that is played on a device with screen size = width x height. Play the game online if you are not familiar with the game.

The snake is initially positioned at the top left corner (0,0) with length = 1 unit.

You are given a list of food's positions in row-column order. When a snake eats the food, its length and the game's score both increase by 1.

Each food appears one by one on the screen. For example, the second food will not appear until the first food was eaten by the snake.

When a food does appear on the screen, it is guaranteed that it will not appear on a block occupied by the snake.

Example:

Given width = 3, height = 2, and food = [[1,2],[0,1]].

Snake snake = new Snake(width, height, food);

Initially the snake appears at position (0,0) and the food at (1,2).

|S| | |
| | |F|

snake.move("R"); -> Returns 0

| |S| |
| | |F|

snake.move("D"); -> Returns 0

| | | |
| |S|F|

snake.move("R"); -> Returns 1 (Snake eats the first food and right after that, the second food appears at (0,1) )

| |F| |
| |S|S|

snake.move("U"); -> Returns 1

| |F|S|
| | |S|

snake.move("L"); -> Returns 2 (Snake eats the second food)

| |S|S|
| | |S|

snake.move("U"); -> Returns -1 (Game over because snake collides with border)


 */


import java.util.LinkedList;

/*
一个一维数组来保存蛇身的位置，由于蛇移动的过程的蛇头向前走一步，蛇尾也跟着往前，中间的躯体还在原来的位置，
所以移动的结果就是，蛇头变到新位置，去掉蛇尾的位置即可。
需要注意的是去掉蛇尾的位置是在检测和蛇身的碰撞之前还是之后，
如果是之后则无法通过这个test case：[[3,3,[[2,0],[0,0]]],["D"],["D"],["U"]]，如果是之前就没有问题了，
检测蛇头和蛇身是否碰撞使用的是count(snake.begin(), snake.end(), head)：
 */
public class LC_0353_DesignSnakeGame {
    public class SnakeGame {
        int[][] food;
        int index;   // food index
        int row, col;  // high and width
        int x, y;    // snake head
        int len;
        LinkedList<int[]> queue;   // snake body

        /**
         * Initialize your data structure here.
         *
         * @param width  - screen width
         * @param height - screen height
         * @param food   - A list of food positions
         *               E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0].
         */
        public SnakeGame(int width, int height, int[][] food) {
            this.food = food;
            this.index = 0;
            this.x = 0;
            this.y = 0;
            this.row = height;
            this.col = width;
            this.queue = new LinkedList<int[]>();
            this.queue.offer(new int[]{0, 0});
        }

        /**
         * Moves the snake.
         *
         * @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
         * @return The game's score after the move. Return -1 if game over.
         * Game over when snake crosses the screen boundary or bites its body.
         */
        public int move(String direction) {
            switch (direction) {
                case "U":
                    x--;
                    break;
                case "L":
                    y--;
                    break;
                case "R":
                    y++;
                    break;
                case "D":
                    x++;
                    break;
            }

            if (!isValid(x, y)) {
                return -1;
            }

            return process(x, y);
        }

        public boolean isValid(int x, int y) {
            if (x < 0 || x >= row || y < 0 || y >= col)
                return false;

            return true;
        }

        public int process(int x, int y) {

            if (index == food.length) {
                queue.poll();

            } else if (food[index][0] == x && food[index][1] == y) {
                len++;
                index++;
            } else {
                queue.poll();
            }

            for (int[] p : queue) {
                if (p[0] == x && p[1] == y)
                    return -1;
            }

            queue.offer(new int[]{x, y});

            return len;
        }
    }
}
