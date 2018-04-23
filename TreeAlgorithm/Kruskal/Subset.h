//
// Created by thamian on 21.05.17.
//

#ifndef P2_SUBSET_H
#define P2_SUBSET_H


// Subset
//
// Określa element podzbioru. Rodzic (parent_) jest reprezentantem podzbioru, bądź
// na niego pośrednio "wskazuje", poprzez śledzenie kolejnych rodziców.
// Rank_ służy do zoptymalizowania łączenia zbiorów.
class Subset {
    friend class Kruskal;

    int parent_;
    int rank_;

public:
    Subset(int parent);
    ~Subset();
};


#endif //P2_SUBSET_H
