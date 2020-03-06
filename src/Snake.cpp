#include "Snake.h"


Snake::Snake(unsigned x, unsigned y){    
    for(int i=0; i<4; i++)
        m_pos.push_back(std::pair<unsigned, unsigned>(x-8*i, y));
}


unsigned Snake::get_size()
    { return m_pos.size(); }


char Snake::get_direction()
    { return direction; }


void Snake::set_pos(int x, int y){
    m_pos.clear();
    for(int i=0; i<32; i++)
        m_pos.push_back(std::pair<unsigned, unsigned>(x-8*i, y));
}


void Snake::set_direction(char c)
        { direction = c; }


void Snake::add_element( )
    { m_pos.push_back(std::pair<unsigned, unsigned>(1000,1000)); }


void Snake::change_pos(){
    for(int i=m_pos.size()-1; i>0; i-- ){
        m_pos[i] = m_pos[i-1];
    }
    
    switch (direction){
        case ('l'):
            m_pos[0] = std::pair<unsigned, unsigned>(m_pos[1].first-8, m_pos[1].second );
            break;
        case ('d'):
            m_pos[0] = std::pair<unsigned, unsigned>(m_pos[1].first, m_pos[1].second+8 );
            break;
        case ('u'):
            m_pos[0] = std::pair<unsigned, unsigned>(m_pos[1].first, m_pos[1].second-8 );
            break;
        default:
            m_pos[0] = std::pair<unsigned, unsigned>(m_pos[1].first+8, m_pos[1].second );
            break;
    }
}


std::pair<unsigned, unsigned> Snake::operator[](int index)
    { return m_pos[index]; }
