#include "Comment.h"

void Comment :: add_reply(std :: string content){
    replies.push_back(new Reply(content, reply_id));
    comment_id++;
}

void Comment :: show_comment(){
    std :: cout << comment_id << ". " << msg << std :: endl;
    for(int i = 0; i < replies.size(); i++){
        std :: cout << comment_id << "." << i+1 << ". " << replies[i]->get_msg() << std :: endl;
    }
}