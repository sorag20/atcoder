for (auto it = mp.begin(); it != mp.end(); ) {
    ans ^= it->second;
    it->second--;
    if (it->second == 0) {
        it = mp.erase(it);
    } else {
        ans ^= it->second;
        ++it;
    }
}