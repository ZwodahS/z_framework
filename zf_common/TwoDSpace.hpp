#ifndef _ZF_COMMON_TWODSPACE_H_
#define _ZF_COMMON_TWODSPACE_H_
#include <vector>
#include "Grid.hpp"
#include <iostream>
template <class T>
class TwoDSpace
{
    public:
        // slightly different from normal iterator
        class Iterator
        {
            public:
                Iterator()
                    :current(_current)
                {
                    _current = Grid(-1,-1);
                    _space = 0;
                }
                // start inclusive
                // end exclusive
                Iterator(Grid start, Grid end, TwoDSpace* space, bool iteratorType)
                    :current(_current)
                {
                    this->_current = start;
                    this->_start = start;
                    this->_end = end;
                    this->_space = space;
                    this->_type = iteratorType;
                }
                ~Iterator()
                {

                }
                
                // get the current value at the iterator
                T get()
                {
                    return _space->get(_current);
                };
                // set the current value at the iterator and return the old value
                T set(T value)
                {
                    return _space->set(_current, value);
                };

                // set this value to empty(the default value specified during space construction) and return the old value
                T empty()
                {
                    return _space->empty(_current);
                }
                bool end()
                {
                    return _current == Grid(-1,-1);
                } 

                Iterator& operator++()
                {
                    return next();
                };
                Iterator& next()
                {
                    if(!end())
                    {
                        if(_type)
                        {
                            if(_start.col <= _end.col)
                            {
                                _current.col++;
                                if(_current.col >= _end.col)
                                {
                                    _current.col = _start.col;
                                    _current.row += _start.row <= _end.row ? 1 : -1;
                                    if(_current.row == _end.row)
                                    {
                                        // end.
                                        _current = Grid(-1,-1);
                                    }
                                }
                            }
                            else
                            {
                                _current.col--;
                               if(_current.col <= _end.col)
                               {
                                    _current.col = _start.col;
                                    _current.row += _start.row <= _end.row ? 1 : -1;
                                    if(_current.row == _end.row)
                                    {
                                        _current = Grid(-1,-1);
                                    }
                               } 
                            }
                        }
                        else
                        {
                            if(_start.row <= _end.row)
                            {
                                _current.row++;
                                if(_current.row >= _end.row)
                                {
                                    _current.row = _start.row;
                                    _current.col += _start.col <= _end.col ? 1 : -1 ;
                                    if(_current.col == _end.col)
                                    {
                                        _current = Grid(-1,-1);
                                    }
                                }
                            }
                            else
                            {
                                _current.row--;
                                if(_current.row <= _end.row)
                                {
                                    _current.row = _start.row;
                                    _current.col += _start.col <= _end.col ? 1 : -1 ;
                                    if(_current.col == _end.col)
                                    {
                                        _current = Grid(-1,-1);
                                    }
                                }
                            }
                        }
                    }
                    return *this;
                };

                const Grid &current;
            protected:

                Grid _current;
                Grid _start;
                Grid _end;
                TwoDSpace* _space; 
                bool _type; // true = row iterator (col++ first) , false = col iterator
        };

        TwoDSpace()
            :row(_row) , col(_col)
        {
            _2dspace = std::vector<std::vector<T> >(0,std::vector<T>(0));
            this->_row = 0;
            this->_col = 0;
        }
        TwoDSpace(int row, int col, T defaultValue)
            :row(_row), col(_col)
        {
            init(row, col, defaultValue);
        }
        void init(int row, int col, T defaultValue)
        {
            _2dspace = std::vector<std::vector<T> >(row, std::vector<T>(col));
            for(int r = 0 ; r < row ; r++)
            {
                for(int c = 0 ; c < col ; c++)
                {
                    _2dspace[r][c] = defaultValue;
                }
            }
            this->_defaultValue = defaultValue;
            this->_row = row;
            this->_col = col;
        }
        T get(int row, int col)
        {
            if(inRange(row,col))
            {
                return _2dspace[row][col];
            }
            else
            {
                return _defaultValue;
            }
        };
        T get(Grid grid)
        {
            return get(grid.row,grid.col);
        }
        T set(int row, int col, T value)
        {
            if(!inRange(row,col))
            {
                return _defaultValue;
            }
            else
            {
                T v = _2dspace[row][col];
                _2dspace[row][col] = value;
                return v;
            }
        }

        T set(Grid grid, T value)
        {
            return set(grid.row, grid.col, value);
        }

        T empty(int row, int col)
        {
            return set(row,col,_defaultValue);
        }

        T empty(Grid grid)
        {
            return empty(grid.row, grid.col);
        }
        
        // return a sub space, topleft and bottom right inclusive.
        // if any of the space is out of range, they will be filled with default value instead.
        // the minimum space is 1/1
        TwoDSpace<T> subspace(Grid topLeft, Grid bottomRight)
        {
            TwoDSpace<T> collision = TwoDSpace<T>(bottomRight.row - topLeft.row  + 1 , bottomRight.col - topLeft.col + 1 , _defaultValue);
            for(int r = topLeft.row, rr = 0 ; r <= bottomRight.row ; r++ , rr++)
            {
                for(int c = topLeft.col, cc = 0 ; c <= bottomRight.col ; c++ , cc++)
                {
                    if(inRange(r,c))
                    {
                        collision.set(rr,cc,get(r,c));
                    }
                }
            }
            return collision;
        }

        bool inRange(int row, int col)
        {
            if(row < 0 || row >= _2dspace.size() || col < 0 || col >= _2dspace[row].size())
            {
                return false;
            }
            return true;
        }

        bool inRange(Grid grid)
        {
            return inRange(grid.row, grid.col);
        }

        Iterator iteratesColRow(bool reversedRow = false , bool reversedCol = false) // col ++ follow by row ++
        {
            Grid start = Grid(0,0);
            Grid end = Grid(_row,_col);
            if(reversedRow)
            {
                start.row = _row-1;
                end.row = -1;
            }
            if(reversedCol)
            {
                start.col = _col-1;
                end.col = -1;
            }
            return Iterator(start,end, this, true);
        }

        Iterator iteratesColRow(Grid start, Grid end)
        {
            return Iterator(start, end, this, true);
        }

        Iterator iteratesRowCol(bool reversedRow = false , bool reversedCol = false) // row ++ follow by col ++
        {
            Grid start = Grid(0,0);
            Grid end = Grid(_row,_col);
            if(reversedRow)
            {
                start.row = _row-1;
                end.row = -1;
            }
            if(reversedCol)
            {
                start.col = _col-1;
                end.col = -1;
            }
            return Iterator(start,end, this, false);
        }

        Iterator iteratesRowCol(Grid start, Grid end)
        {
            return Iterator(start,end,this,false);
        }
        const int &row;
        const int &col;
    private:
        std::vector<std::vector<T> > _2dspace;
        T _defaultValue;
        int _row;
        int _col;
};

#endif
