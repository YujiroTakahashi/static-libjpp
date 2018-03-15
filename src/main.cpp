#include <fstream>
#include <iostream>

#include "jpp.h"

int main(int argc, const char** argv)
{
    croco::Jpp jpp("/usr/local/libexec/jumanpp/jumandic.jppmdl");

    std::string input("魅力がたっぷりと詰まっている");
    nlohmann::json retval = jpp.analyze(input);

    for (auto &val : retval) {
        std::cout << val["surface"].get<std::string>();
        if (val.find("subtext") != val.end()) {
            std::cout << "::" << val["subtext"] << "\n";
        } else {
            std::cout << "\n";
        }
    }
    std::cout << std::endl;

    return 0;
}
