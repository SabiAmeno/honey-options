#include <QCoreApplication>
#include <iostream>

#include "honeyoptions.h"

static option opt[] = {
	{ "server", "s", 1 },
	{ "port", "p", 1 },
	{ "user", "u", 1 },
	{ "help", "h", 0 },
	{ "psswd", "w", 2 }
};

void usage();

int main(int argc, char *argv[])
{
    HoneyOptions honey_opt;
    honey_opt.setopts(opt);
    bool res = honey_opt.process(argc, argv);
    if(res) {
        std::cout << honey_opt["s"] << std::endl;
        std::cout << honey_opt["p"] << std::endl;
        std::cout << honey_opt["u"] << std::endl;
        std::cout << honey_opt["w"] << std::endl;

        if(honey_opt.hasopt("h") || honey_opt.hasopt("help"))
            usage();
    } else
        usage();
    return 0;
}

void usage()
{
    std::string usg = "Usage:\n";
    usg += "\t --server or -s:add server address\n";
    usg += "\t --port or -p: add port\n";
    usg += "\t --user or -u: add user name\n";

    std::cout << usg;
}
