class SnakeGame {
private:
    int score;
    queue<pair<int,int>> foodStack;
    set<pair<int,int>> body;
    list<pair<int,int>> snake;
    unordered_map<string, pair<int, int>> dir;
    int w,h;
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food) {
        score = 0;
        w = width;
        h = height;
        for(int i = 0; i < food.size(); i ++)
            foodStack.push(food[i]);
        dir["U"] = make_pair(-1, 0);
        dir["L"] = make_pair(0, -1);
        dir["R"] = make_pair(0, 1);
        dir["D"] = make_pair(1, 0);
        snake.push_back(make_pair(0,0));
        body.insert(make_pair(0,0));
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        int curX = snake.front().first;
        int curY = snake.front().second;
        int nextX = curX + dir[direction].first;
        int nextY = curY + dir[direction].second;
        if(nextX < 0 || nextY < 0 || nextX >= h || nextY >= w)
            return -1;
        int lastX = snake.back().first;
        int lastY = snake.back().second;
        if(body.find(make_pair(nextX, nextY)) != body.end() && !(nextX == lastX && nextY == lastY))
            return -1;
        snake.push_front(make_pair(nextX, nextY));
        if(!foodStack.empty()) {
            int foodX = foodStack.front().first;
            int foodY = foodStack.front().second;
            if(foodX == nextX && foodY == nextY) {
                body.insert(snake.front());
                score ++;
                foodStack.pop();
                return score;
            }
        }
        body.erase(snake.back());
        body.insert(snake.front());
        snake.pop_back();
        return score;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */
