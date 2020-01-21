#include "interfaces.h"
#include <string>
#include "StringReverser.h"
#include "FileCacheManager.h"
#include "MyTestClientHandler.h"
namespace boot {
	class Main {
	public:
		int main(int argc, char* argv[]);
	};
	int Main::main(int argc, char* argv[]) {
		Solver< std::string, std::string> sol = StringReverser();
		FileCacheManager<std::string>* cm = new FileCacheManager<std::string>();
		MyTestClientHandler* handle = new MyTestClientHandler(sol, cm);
		
		server_side::Server server = MySerialServer();
		server.open(argv[0], handle);
	}
}

