#include <bits/stdc++.h>
#define int long long
using namespace std;
#define MOD 1000000007

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

class Triplet
{
public:
    int __First = -1;
    int __Second = -1;
    int __Third = -1;
    Triplet(int __First, int __Second, int __Third)
    {
        this->__First = __First, this->__Second = __Second, this->__Third = __Third;
    }
    Triplet() {}
};

class MATH
{
public:
    int __BinExpRec(int __Base, int __Pow, int __Mod = MOD)
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

    int __BinExpItr(int __Base, int __Pow, int __Mod = MOD)
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

    Triplet __AnySolution(int __Num1, int __Num2, int __Const)
    {
        Triplet __Soln;
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
        x += __cnt * __Num2;
        y -= __cnt * __Num1;
    }

    int __AllSolutions(int __Num1, int __Num2, int __Const, int Minx, int Maxx, int Miny, int Maxy)
    {
        // ^ Each Time We Can Get A New Solution By Transforming X and Y as ,
        // ^ x1 = x + k * (__Num2/__Gcd) , y1 = y - k * (__Num1/__Gcd).
        Triplet __Soln;
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
        Triplet __Soln;
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
        Triplet __Soln;
        __Soln = __AnySolution(__Num1, __Num2, __Const);
        return (__Soln.__First + __Soln.__Second);
    }
    
};

void solve(void)
{
    MATH obj;
    Triplet tr = obj.__AnySolution(68, 64, 128);
    debug(tr.__First, tr.__Second, tr.__Third);
    debug(obj.__AllSolutions(2, 4, 2, -4, 4, -2, 2));
    debug(obj.__MinSum(8, 4, 4));
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
