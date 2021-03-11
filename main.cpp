#include "./src/codingInterviews/01_AssignmentOperator/AssignmentOperator.h"

//int main() {
//    /// test ./src/01_AssignmentOperator/AssignmentOperator.h
//    CMyString::Test1();
//    CMyString::Test2();
//    CMyString::Test3();
//
//    return 0;
//}

bool third_party_func(int, char, float) { return true; }

template<typename funcT>
void invoker(funcT callback_func) {
    callback_func(int());
}

// C++ style adaptor
class adaptor_functor {
public:
    // Initialize runtime bindings
    adaptor_functor(char cb, float fb) : cb_(cb), fb_(fb) {}

    void operator()(int n) {
        third_party_func(cb_, fb_, n);
    }

private:
    char cb_;
    float fb_;
};

int main() {

    // C++ functor has bindings that can be set ar runtime via the functors constructor
    invoker(adaptor_functor('a', 2.3f));
    invoker(adaptor_functor('z', 0.0f));
}
