#!/usr/bin/env python3

import sys

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
        self._bounds = (-30, -30, 30, 30) # all inclusive

    @property
    def position(self):
        return self._position

    @property
    def orientation(self):
        return self._orientation

    @property
    def bounds(self):
        return self._bounds

    # maxx and maxy are exclusive
    def _resize_board(self, minx=None, maxx=none, miny=None, maxy=None):
        if sum(int(bool(i)) for i in (minx, maxx, miny, maxy)) != 1:
            e = ValueError('Exactly one of minx, maxx, miny, maxy should be True')
            raise e

        if minx is not None:
            self._internal = [row[minx:] for row in self._internal]
        elif maxx is not None:
            self._internal = [row[:maxx] for row in self._internal]
        elif miny is not None:
            self._internal = [row[:] for row in self._internal[miny:]]
        else:
            self._internal = [row[:] for row in self._internal[:maxy]]

    def _update(self, )

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
            print {'u': 'UP', 'd': 'DOWN', 'l': 'LEFT', 'r': 'RIGHT'}[direction]
            self._update([list(row.strip()) for row in (input(), input(), input())], )
            self._position = (targetx, targety)
        else:
            # Should never reach a tile that is EXIT (program should just exit)
            # or UNEXPLORED (neighbor tiles are always visible, so a bot should never)
            # land on a tile before it is seen
            e = RuntimeError('Erroneously reached an EXIT or UNEXPLORED tile')
            raise e

    def __getitem__(self, sel):
        return self._internal[sel[0]+self._offset[0]][sel[1]+self._offset[1]]
