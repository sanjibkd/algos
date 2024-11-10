**Get 64-bit pattern as a string**
string sx = bitset<64>(x).to_string();

**Convert bit pattern in string to long long**
long long res = stoll(sx, nullptr, 2);
