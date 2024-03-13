#include <iostream>
#include <map>
#include <cstdint>
#include <memory>

enum class Index:std::uintmax_t {
	Root,
	A,
	B,
	C,
	D,
};

template<class E,class T>
class IndexMappedGraph {
public:


	struct Node;
	struct Node {
		typedef std::shared_ptr<Node> SharedNode;
		E ID{};
		T V{};
		std::map<E, SharedNode> Nodes;
		SharedNode operator [](E In) {
			return Nodes[In];
		}
		bool Find(E In) {
			return Nodes.find(In) != Nodes.end();
		}
		bool Push(E N, SharedNode S) {
			if (Find(N) == true) { return false; }
			Nodes[N] = S;
			return true;
		}
		bool Erase(E In) {
			auto X = Nodes.find(In);
			return Nodes.erase(X);
		}
	};


	Node& GerRoot() {
		return N;
	}

protected:
	Node N;
};

int main() {
	IndexMappedGraph<Index, int> X;//i cant write all service in this. who are kill me? i need Graph.
	X.GerRoot().ID = Index::Root;
	X.GerRoot().Push(Index::A, std::shared_ptr<IndexMappedGraph<Index, int>::Node>());
	X.GerRoot().Push(Index::B, std::shared_ptr<IndexMappedGraph<Index, int>::Node>());
	X.GerRoot().Push(Index::C, std::shared_ptr<IndexMappedGraph<Index, int>::Node>());
	X.GerRoot().Push(Index::D, std::shared_ptr<IndexMappedGraph<Index, int>::Node>());
}
