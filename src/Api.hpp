#ifndef API_HPP
#define API_HPP

#include <pistache/net.h>
#include <pistache/endpoint.h>
#include <pistache/router.h>
#include <pistache/description.h>

class Api {
public:
    explicit Api(Pistache::Address addr);
    virtual ~Api();

    void start();

    void doSomething(const Pistache::Rest::Request& request, Pistache::Http::ResponseWriter response);

private:
    Pistache::Http::Endpoint m_httpEndpoint;
    Pistache::Rest::Description m_desc;
    Pistache::Rest::Router m_router;
};

#endif // !API_HPP
