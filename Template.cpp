#include <bits/stdc++.h>
#define int long long
using namespace std;
#define __MOD 1000000007
#define __Sz 2

void __print(signed x)
{
    cerr << x;
}
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename A>
void __print(const A &x);
template <typename A, typename B>
void __print(const pair<A, B> &p);
template <typename... A>
void __print(const tuple<A...> &t);
template <typename T>
void __print(stack<T> s);
template <typename T>
void __print(queue<T> q);
template <typename T, typename... U>
void __print(priority_queue<T, U...> q);
template <typename A>
void __print(const A &x)
{
    bool first = true;
    cerr << '{';
    for (const auto &i : x)
    {
        cerr << (first ? "" : ","), __print(i);
        first = false;
    }
    cerr << '}';
}
template <typename A, typename B>
void __print(const pair<A, B> &p)
{
    cerr << '(';
    __print(p.first);
    cerr << ',';
    __print(p.second);
    cerr << ')';
}
template <typename... A>
void __print(const tuple<A...> &t)
{
    bool first = true;
    cerr << '(';
    apply([&first](const auto &...args)
          { ((cerr << (first ? "" : ","), __print(args), first = false), ...); },
          t);
    cerr << ')';
}
template <typename T>
void __print(stack<T> s)
{
    vector<T> debugVector;
    while (!s.empty())
    {
        T t = s.top();
        debugVector.push_back(t);
        s.pop();
    }
    reverse(debugVector.begin(), debugVector.end());
    __print(debugVector);
}
template <typename T>
void __print(queue<T> q)
{
    vector<T> debugVector;
    while (!q.empty())
    {
        T t = q.front();
        debugVector.push_back(t);
        q.pop();
    }
    __print(debugVector);
}
template <typename T, typename... U>
void __print(priority_queue<T, U...> q)
{
    vector<T> debugVector;
    while (!q.empty())
    {
        T t = q.top();
        debugVector.push_back(t);
        q.pop();
    }
    __print(debugVector);
}
void _print() { cerr << "]\n"; }
template <typename Head, typename... Tail>
void _print(const Head &H, const Tail &...T)
{
    __print(H);
    if (sizeof...(T))
        cerr << ", ";
    _print(T...);
}
#ifndef ONLINE_JUDGE
#define debug(...)                                                  \
    cerr << "Line:" << __LINE__ << " [" << #__VA_ARGS__ << "] = ["; \
    _print(__VA_ARGS__)
#else
#define debug(...)
#endif

class __Triplet
{
public:
    int __First = -1;
    int __Second = -1;
    int __Third = -1;
    __Triplet(int __First, int __Second, int __Third)
    {
        this->__First = __First, this->__Second = __Second, this->__Third = __Third;
    }
    __Triplet() {}
};

struct __Matrix
{
    long long __Mat[__Sz][__Sz];
    __Matrix friend operator*(const __Matrix &__Mat1, const __Matrix &__Mat2)
    {
        __Matrix __Res;
        for (int i = 0; i < __Sz; i++)
            for (int j = 0; j < __Sz; j++)
            {
                __Res.__Mat[i][j] = 0;
                for (int k = 0; k < __Sz; k++)
                    __Res.__Mat[i][j] = (__Res.__Mat[i][j] + __Mat1.__Mat[i][k] * __Mat2.__Mat[k][j]) % __MOD;
            }
        return __Res;
    }
};

class __MATH
{
public:
    int __BinExpRec(int __Base, int __Pow, int __Mod = __MOD)
    {
        // * APPLICATIONS :-
        // ^ Used To Calculate (__Base ^ __Pow) % __Mod in  O(logN) Time.
        // ^ When __Pow Is Very Big Than __Mod Then (__Base ^ __Pow) % __Mod = (__Base ^ (__Pow % Phi(__Mod))) % __Mod.
        if (__Pow == 0)
            return 1;
        int __Res = __BinExpRec(__Base, __Pow / 2, __Mod);
        if (__Pow & 1)
            return ((__Res * __Res) % __Mod * __Base) % __Mod;
        return (__Res * __Res) % __Mod;
    }

    int __BinExpItr(int __Base, int __Pow, int __Mod = __MOD)
    {
        int __Res = 1;
        while (__Pow)
        {
            if (__Pow & 1)
                __Res = (__Res * __Base) % __Mod;
            __Base = (__Base * __Base) % __Mod;
            __Pow >>= 1;
        }
        return __Res;
    }

    __Matrix __MatExp(__Matrix __Base, int __Num)
    {
        __Matrix __Res = {{{1, 0}, {0, 1}}};
        while (__Num)
        {
            if (__Num & 1)
                __Res = __Res * __Base;
            __Base = __Base * __Base;
            __Num >>= 1;
        }
        return __Res;
    }

    int __Gcd(int __Num1, int __Num2)
    {
        // ^ Extended Euclid Algorithm __Gcd(__Num1 , __Num2) = __Gcd(__Num2 , __Num1 % __Num2).
        if (__Num2 == 0)
            return __Num1;
        return __Gcd(__Num2, __Num1 % __Num2);
    }

    int __Lcm(int __Num1, int __Num2)
    {
        // ^ Lcm And Hcf Property __Lcm * __Gcd = __Num1 * __Num2.
        return __Num1 / __Gcd(__Num1, __Num2) * __Num2;
    }

    int __FastGcd(int __Num1, int __Num2)
    {
        // ^ __Gcd(2 * __Num1 , 2 * __Num2) = 2 * __Gcd(__Num1 , __Num2) , Both Even.
        // ^ __Gcd(__Num1 , 2 * __Num2) = __Gcd(__Num1 , __Num2) , One Odd One Even.
        // ^ __Gcd(__Num1 , __Num2) = __Gcd(__Num2 , __Num1 - __Num2) , Both Odd.
        if (!__Num1 || !__Num2)
            return __Num1 | __Num2;
        unsigned shift = __builtin_ctz(__Num1 | __Num2);
        __Num1 >>= __builtin_ctz(__Num1);
        do
        {
            __Num2 >>= __builtin_ctz(__Num2);
            if (__Num1 > __Num2)
                swap(__Num1, __Num2);
            __Num2 -= __Num1;
        } while (__Num2);
        return __Num1 << shift;
    }

    int __ExtendedGcd(int __Num1, int __Num2, int &x, int &y)
    {
        // ^ If __Num1 * X + __Num2 * Y = __Gcd(__Num1 , __Num2) Then There Exist ,
        // ^ __Num2 * X1 + (__Num1 % __Num2) * Y1 = __Gcd(__Num1 , __Num2) For Some X1 , Y1.
        if (__Num2 == 0)
        {
            // ^ Base Case __Num1 * X + __Num2 * Y = __Gcd(__Num1 , __Num2).
            x = 1, y = 0;
            return __Num1;
        }
        int x1, y1;
        int __Gcd = __ExtendedGcd(__Num2, __Num1 % __Num2, x1, y1);
        // ^ Applying the Base Case In the Backtracking Step.
        x = y1, y = x1 - y1 * (__Num1 / __Num2);
        return __Gcd;
    }

    __Triplet __AnySolution(int __Num1, int __Num2, int __Const)
    {
        __Triplet __Soln;
        // ^ Assuming The Eqn To be  __Num1 * X + __Num2 * Y = __Gcd(__Num1 , __Num2) Now ,
        // ^ Now Extending The Same Across __Const With Multiples Of __Gcd.
        __Soln.__Third = __ExtendedGcd(abs(__Num1), abs(__Num2), __Soln.__First, __Soln.__Second);
        if (__Const % __Soln.__Third)
            return {-1, -1, -1};
        __Soln.__First *= __Const / __Soln.__Third, __Soln.__Second *= __Const / __Soln.__Third;
        if (__Num1 < 0)
            __Soln.__First = -__Soln.__First;
        if (__Num2 < 0)
            __Soln.__Second = -__Soln.__Second;
        return __Soln;
    }

    void __ShiftSoln(int &x, int &y, int __Num1, int __Num2, int __cnt)
    {
        // ^ This Get The Min possible Value of X and Y by Shifting the Values Correspondingly.
        x += __cnt * __Num2;
        y -= __cnt * __Num1;
    }

    int __AllSolutions(int __Num1, int __Num2, int __Const, int Minx, int Maxx, int Miny, int Maxy)
    {
        // ^ Each Time We Can Get A New Solution By Transforming X and Y as ,
        // ^ x1 = x + k * (__Num2/__Gcd) , y1 = y - k * (__Num1/__Gcd).
        __Triplet __Soln;
        __Soln = __AnySolution(__Num1, __Num2, __Const);
        if (__Soln.__First == -1 && __Soln.__Second == -1 && __Soln.__Third == -1)
            return 0;
        __Num1 /= __Soln.__Third;
        __Num2 /= __Soln.__Third;
        int sign_a = __Num1 > 0 ? +1 : -1;
        int sign_b = __Num2 > 0 ? +1 : -1;
        __ShiftSoln(__Soln.__First, __Soln.__Second, __Num1, __Num2, (Minx - __Soln.__First) / __Num2);
        if (__Soln.__First < Minx)
            __ShiftSoln(__Soln.__First, __Soln.__Second, __Num1, __Num2, sign_b);
        if (__Soln.__First > Maxx)
            return 0;
        int __Leftx = __Soln.__First;
        __ShiftSoln(__Soln.__First, __Soln.__Second, __Num1, __Num2, (Maxx - __Soln.__First) / __Num2);
        if (__Soln.__First > Maxx)
            __ShiftSoln(__Soln.__First, __Soln.__Second, __Num1, __Num2, -sign_b);
        int __Rightx = __Soln.__First;
        __ShiftSoln(__Soln.__First, __Soln.__Second, __Num1, __Num2, -(Miny - __Soln.__Second) / __Num1);
        if (__Soln.__Second < Miny)
            __ShiftSoln(__Soln.__First, __Soln.__Second, __Num1, __Num2, -sign_a);
        if (__Soln.__Second > Maxy)
            return 0;
        int __Lefty = __Soln.__First;
        __ShiftSoln(__Soln.__First, __Soln.__Second, __Num1, __Num2, -(Maxy - __Soln.__Second) / __Num1);
        if (__Soln.__Second > Maxy)
            __ShiftSoln(__Soln.__First, __Soln.__Second, __Num1, __Num2, sign_a);
        int __Righty = __Soln.__First;
        if (__Lefty > __Righty)
            swap(__Lefty, __Righty);
        int Left = max(__Leftx, __Lefty);
        int Right = min(__Rightx, __Righty);
        if (Left > Right)
            return 0;
        return (Right - Left) / abs(__Num2) + 1;
    }

    int __MinSum(int __Num1, int __Num2, int __Const)
    {
        /*
        // ^ Minimum Value Of (x + y) Where x, y Are Non Negative Integers.
        __Triplet __Soln;
        __Soln = __AnySolution(__Num1, __Num2, __Const);
        if (__Soln.__First == -1 && __Soln.__Second == -1 && __Soln.__Third == -1)
            return -1;
        __Num1 /= __Soln.__Third;
        __Num2 /= __Soln.__Third;
        int sign_a = __Num1 > 0 ? +1 : -1;
        int sign_b = __Num2 > 0 ? +1 : -1;
        __ShiftSoln(__Soln.__First, __Soln.__Second, __Num1, __Num2, -__Soln.__First / __Num2);
        if (__Soln.__First < 0)
            __ShiftSoln(__Soln.__First, __Soln.__Second, __Num1, __Num2, sign_b);
        int minx1 = __Soln.__First;
        __ShiftSoln(__Soln.__First, __Soln.__Second, __Num1, __Num2, __Soln.__Second / __Num1);
        if (__Soln.__Second < 0)
            __ShiftSoln(__Soln.__First, __Soln.__Second, __Num1, __Num2, -sign_a);
        int minx2 = __Soln.__First;
        if (minx2 > __Soln.__First)
            swap(minx2, __Soln.__First);
        int minx = max(minx1, minx2);
        if (minx > __Soln.__First)
            return -1;
        int miny = (__Const - __Num1 * __Soln.__First) / __Num2;
        return (miny + minx);
        */
        // ^ The Base Solution of __AnySolution Will Always Give the Minimum Sum of X + Y.
        __Triplet __Soln;
        __Soln = __AnySolution(__Num1, __Num2, __Const);
        if (__Soln.__First != -1 && __Soln.__Second != -1 && __Soln.__Third != -1)
            return (__Soln.__First + __Soln.__Second);
        else
            return INT_MIN;
    }

    int __FibonacciFormula(int __Num)
    {
        // ^ Formula of Fib(n) = (((1 + sqrt(5))/2)^__Num - ((1 - sqrt(5))/2)^__Num)/sqrt(5).
        return ((1 / sqrt(5)) * (pow((1 + sqrt(5)) / 2.0, __Num) - pow((1 - sqrt(5)) / 2.0, __Num)));
    }
    int __FibonacciItr(int __Num, int __Mod = __MOD)
    {
        // ^ Fib(n) = Fib(n-1) + Fib(n-2).
        if (__Num == 0)
            return 0;
        if (__Num == 1)
            return 1;
        int __Prev = 0;
        int __Curr = 1;
        for (int i = 2; i <= __Num; i++)
        {
            swap(__Prev, __Curr);
            __Curr = (__Prev + __Curr) % __MOD;
        }
        return __Curr;
    }
    long long __FibExp(int n)
    {
        __Matrix __Base = {{{1, 1}, {1, 0}}};
        return __MatExp(__Base, n).__Mat[0][1];
    }
};

void solve(void)
{
    __MATH obj;
    debug(obj.__FibonacciItr(1), obj.__FibonacciItr(2), obj.__FibonacciItr(3), obj.__FibonacciItr(4));
    debug(obj.__FibExp(300), obj.__FibonacciItr(300));
}

signed main(void)
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    int _ = 1;
    // cin >> _;
    while (_--)
        solve();
    return 0;
}
