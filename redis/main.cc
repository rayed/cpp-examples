#include <iostream>

#include <hiredis.h>


bool redis_test()
{
    redisContext *c;
    redisReply *reply;

    c = redisConnect("127.0.0.1", 6379);
    if (c != NULL && c->err) {
        std::cerr << "Error: " << c->errstr << std::endl;
        // handle error
        return false;
    }
    for(uint32_t i=0; i<1e4; i++) {
        // Set
        reply = (redisReply *)redisCommand(c, "SET name %s", "rayed");
        freeReplyObject(reply);
        // Get
        reply = (redisReply *)redisCommand(c, "GET name");
        //std::cout << "GET: " << reply->str << std::endl;
        freeReplyObject(reply);
    }
    redisFree(c);
    return true;
}

int main()
{
    std::cout << "==== Starting ====" << std::endl;
    redis_test();
    return 0;
}
