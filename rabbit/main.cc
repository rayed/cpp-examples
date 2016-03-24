#include <iostream>

#include <SimpleAmqpClient/SimpleAmqpClient.h>


bool rabbit_test()
{
    std::string queue = "hello";
    AmqpClient::Channel::ptr_t channel = AmqpClient::Channel::Create("localhost");
    channel->DeclareQueue(queue, false, false, false, false);

    // send message
    AmqpClient::BasicMessage::ptr_t msg_in = AmqpClient::BasicMessage::Create();
    msg_in->Body("This is a small message.");
    channel->BasicPublish("", queue, msg_in);

    // recive message
    std::string consumer_tag = channel->BasicConsume(queue, "");
    AmqpClient::Envelope::ptr_t envelope;
    while (true) {
        channel->BasicConsumeMessage(consumer_tag, envelope);
        std::cout << envelope->Message()->Body() << std::endl;
    }
    return true;
}

int main()
{
    std::cout << "==== Starting ====" << std::endl;
    rabbit_test();
    return 0;
}
