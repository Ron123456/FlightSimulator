//
// Created by amitnir29 on 17/01/2020.
//

#ifndef EX4_INTERFACES_H
#define EX4_INTERFACES_H

namespace client_handler {
    class ClientHandler {
    public:
        virtual int handleClient(int socket) = 0;
    };
}

namespace server_side {
    class Server {
        int port;
    public:
        virtual int open(int port, client_handler::ClientHandler* c) = 0;
        virtual int close() = 0;
    };
}

namespace problem_solving {
    template <typename Problem, typename Solution> 
	class Solver{
    public:
        virtual Solution solve(Problem p) = 0;
    };
	template <typename Problem, typename Solution>
    class CacheManager {
    public:
        virtual bool hasSolution(Solution s) = 0;
        virtual Solution getSolution(Problem p) = 0;
        virtual int setSolution(Problem p, Solution s) = 0;
    };
}

#endif //EX4_INTERFACES_H
