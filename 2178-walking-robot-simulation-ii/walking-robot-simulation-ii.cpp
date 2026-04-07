class Robot {
public:
    int w = 0;
    int h = 0;
    int x = 0;
    int y = 0;
    bool no = false;
    bool sou = false;
    bool east = true;
    bool west = false;
    Robot(int width, int height) {
        w = width-1;
        h = height-1;
    }
    
    void step(int num) {
       num = num%(2*(w+h));
       if(num == 0){
        num = 2*(w+h);
       }
       while(num--){
        if(no){
            if(y+1 > h){
                num++;
                no = false;
                west = true;
                continue;
            }
            else{
                y++;
            }
        }
        else if(west){
            if(x-1 < 0){
                num++;
                west = false;
                sou = true;
                continue;
            }
            else{
                x--;
            }
        }
        else if(sou){
            if(y-1 < 0){
                num++;
                sou = false;
                east = true;
                continue;
            }
            else{
                y--;
            }
        }
        else if(east){
            if(x+1 > w){
                num++;
                east = false;
                no = true;
                continue;
            }
            else{
                x++;
            }
        }
       }
    }
    
    vector<int> getPos() {
        return {x,y};
    }
    
    string getDir() {
        if(no){
            return "North";
        }
        else if(sou){
            return "South";
        }
        else if(west){
            return "West";
        }
        return "East";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */