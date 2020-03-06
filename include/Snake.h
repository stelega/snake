#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

// class representing a snake
class Snake{

public:
    // constructor seting starting position of a snake
    Snake(unsigned x, unsigned y);
    // function returning snakes size;
    unsigned get_size();
    //  function returning direction 
    char get_direction();
    // function setting position of a snake
    void set_pos(int x, int y);
    // function setting direction of a snake
    void set_direction(char c);
    // function adding element to vector 'm_pos'
    void add_element( );
    // function changing snakes position
    void change_pos();
    // operator [] returning an element of 'm_pos' vector of index 'i'
    std::pair<unsigned, unsigned> operator[](int i);

private:
    std::vector<std::pair<unsigned, unsigned>> m_pos;
    // direction in which snake is moving
    char direction = 'r';

};
