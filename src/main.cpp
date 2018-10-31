#include "Api.hpp"

#include <stdexcept>

int main() {
    try {
        Pistache::Address addr(Pistache::Ipv4::any(), Pistache::Port(80)); // Assuming we don't have root privileges ; trying to bind to 80 should fail
        Api api(addr);
        api.start(); // This should throw an error because we bind agains port 80 without being root.
    }
    catch (...) {
        // If we get here, it means the destructor of Api, which calls httpEndpoint.shutdown(), was called.
        std::cout << "Got exception." << std::endl;
        return 1;
    }
    return 0;
}
