#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>

#include <boost/program_options.hpp>

namespace po = boost::program_options;


bool config_read(int ac, char * av[], po::variables_map& vm) {

    try {
        // Build option set
        po::options_description generic("Generic options");
        generic.add_options()
            ("version,v", "print version string")
            ("help", "produce help message")
            ("optimization,o", po::value<int>()->default_value(10), "optimization level")
            ;
        po::options_description cli("CLI options");
        cli.add_options()
            ("config,c", po::value<std::string>()->default_value("config.cfg"), "read configuration from file")
            ;
        po::options_description file("Configuration");
        file.add_options()
            ("section.level", po::value<int>()->default_value(10), "Section Level")
            ("include-path,I", po::value<std::vector<std::string>>()->composing(), "include path")
            ;

        // Group options toegther
        po::options_description cli_options;
        cli_options.add(generic).add(cli);
        po::options_description file_options;
        file_options.add(generic).add(file);

        // Parse Options
        // ... from CLI
        po::store(po::parse_command_line(ac, av, cli_options), vm);
        po::notify(vm);
        // ... from file
        std::ifstream ifs(vm["config"].as<std::string>());
        store(parse_config_file(ifs, file_options), vm);
        notify(vm);

        // Show help
        if (vm.count("help")) {
            std::cout << "Usage: " << av[0] << " [options] input-files\n";
            std::cout << cli_options << "\n";
            return false;
        }
    } catch(std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
        return false;
    }
    return true;
}

int main(int ac, char * av[]) {

    std::cout << "==== Sample Config ====" << std::endl;

    po::variables_map config;
    config_read(ac, av, config);

    if (config.count("optimization")) {
        std::cout << "optimization level was set to "
     << config["optimization"].as<int>() << ".\n";
    } else {
        std::cout << "optimization level was not set.\n";
    }

    if (config.count("section.level")) {
        std::cout << "Section level: " << config["section.level"].as<int>() << ".\n";
    }

    return 0;
}
