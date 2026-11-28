// test 1

// int main()
// {
//     auto lam = [](int x) { return x * 2; };
//     return lam(5);
// }

/// test2
auto make_lambda()
{
    return [](int x) {
        return x + 1;
    };
}

int call_lambda()
{
    auto lambda = [](int x) {
        return x * 2;
    };

    return lambda(5);
}

////  nm lambda.o -> t _ZZ11call_lambdavENKUliE_clEi
////  nm -C lambda.o -> t call_lambda()::{lambda(int)#1}::operator()(int) const