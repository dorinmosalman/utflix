#include <iostream>
#include <string>
#include <vector>

class Comment{
public:
    Comment(std :: string init_msg, int id): msg(init_msg), comment_id(id){}


private:
    std :: string msg;
    std :: vector<std :: string> replies;
    int comment_id;
};