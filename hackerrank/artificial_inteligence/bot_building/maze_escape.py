#!/usr/bin/env python3

import sys
import itertools

class Board():
    EXIT = 'e'
    EMPTY = '-'
    BLOCKED = '#'
    UNEXPLORED = '?'
    _tile_states = (EXIT, EMPTY, BLOCKED, UNEXPLORED)

    def __init__(self, r=30*2+1, c=30*2+1):
        self._internal = [[Board.UNEXPLORED for i in range(c)] for j in range(r)]
        self._offset = (30, 30) # the actual index of (0, 0) in self._internal
        self._position = (0, 0) # the current location on the board (not in self._internal)
        self._orientation = 'u'
        self._bounds = (-30, 30, -30, 30) # all inclusive
        self._update([tuple(sys.stdin.readline().strip('\n').lower()) for i in range(3)])

    @property
    def position(self):
        return self._position

    @property
    def orientation(self):
        return self._orientation

    @property
    def bounds(self):
        return self._bounds

    def __getitem__(self, sel):
        return self._internal[sel[1]+self._offset[1]][sel[0]+self._offset[0]]

    def __setitem__(self, sel, obj):
        old = self[sel]
        self._internal[sel[1]+self._offset[1]][sel[0]+self._offset[0]] = obj
        return old

    def __str__(self):
        s = ''
        for y in range(self._bounds[2], self._bounds[3]):
            for x in range(self._bounds[0], self._bounds[1]):
                s += self[x, y]
            s += '\n'
        return s[:-1]

    def move(self, direction):
        direction = direction.lower()
        if direction not in 'udlr':
            e = ValueError("direction must be 'u', 'd', 'l', or 'r'")
            raise e

        targetx, targety = self._position
        if direction == 'u':
            targety -= 1
        elif direction == 'd':
            targety += 1
        elif direction == 'l':
            targetx -= 1
        else:
            targetx += 1

        bounds = self._bounds
        if targetx < bounds[0] or targetx > bounds[1] or targety < bounds[2] or targety > bounds[3]:
            # Really shouldn't get here based on the boards, but just in case
            e = ValueError('Can\'t leave the board')
            raise e

        if self[targetx, targety] == Board.BLOCKED:
            e = ValueError('Can\'t move into a blocked space')
            raise e
        elif self[targetx, targety] == Board.EMPTY:
            print({'u': 'UP', 'd': 'DOWN', 'l': 'LEFT', 'r': 'RIGHT'})[direction]
            self._orientation = direction
            self._position = (targetx, targety)
            self._update([tuple(sys.stdin.readline().strip('\n').lower()) for i in range(3)])
            return self._position
        elif self[targetx, targety] == Board.EXIT:
            pass
        else:
            # Should never reach a tile that is UNEXPLORED (neighbor tiles are
            # always visible, so a bot should never land on a tile before it is seen)
            e = RuntimeError('Erroneously reached an UNEXPLORED tile')
            raise e

    def _update(self, vision):
        if self._orientation == 'd':
            for row in vision:
                row.reverse()
            vision.reverse()
        elif self._orientation == 'l':
            vision = list(zip(*vision))
            vision.reverse()
        elif self._orientation == 'r':
            vision.reverse()
            vision = list(zip(*vision))

        for x,y in set(itertools.product(range(-1,2), repeat=2)) - set([(0, 0)]):
            board_position = (self.position[0] + x, self.position[0] + y)
            if self[board_position] == Board.UNEXPLORED:
                self[board_position] = vision[y+1][x+1]
            elif self[board_position] != vision[y+1][x+1]:
                e = RuntimeError('Robot\'s vision inconsistent with board')
                raise e

if __name__ == '__main__':
    b = Board()
