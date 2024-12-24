ll power(ll a, ll b, ll m)
{
    if (b == 0)
    {
        return 1;
    }
    ll pr = power(a, b / 2, m);
    if (b % 2)
    {
        return (((pr * pr) % m) * a) % m;
    }
    else
    {
        return (pr * pr) % m;
    }
}
