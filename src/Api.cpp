#include "Api.hpp"

#include <stdexcept>

Api::Api(Pistache::Address addr)
    : m_httpEndpoint(addr)
    , m_desc("Bruce Lee's website", "0.1")
{
    auto opts = Pistache::Http::Endpoint::options();
    m_httpEndpoint.init(opts);

    m_desc
            .info()
            .license("Apache", "http://www.apache.org/licenses/LICENSE-2.0");

    auto backendErrorResponse =
            m_desc.response(Pistache::Http::Code::Internal_Server_Error, "An error occurred with the backend");

    m_desc
            .schemes(Pistache::Rest::Scheme::Http)
            .produces(MIME(Application, Json))
            .consumes(MIME(Application, Json));
    

    auto usagerPath = m_desc.path("/");

    usagerPath
            .route(m_desc.get("/myressource"))
            .bind(&Api::doSomething, this)
            .hide();

    m_router.initFromDescription(m_desc);

    Pistache::Rest::Swagger swagger(m_desc);
    swagger
            .install(m_router);

    m_httpEndpoint.setHandler(m_router.handler());
}

Api::~Api()
{
    m_httpEndpoint.shutdown();
}

void Api::start() {
    m_httpEndpoint.serve();
}

void Api::doSomething(const Pistache::Rest::Request& request, Pistache::Http::ResponseWriter response) {
    std::cout << "Sorry, Chuck Norris shut down this website." << std::endl;
}
