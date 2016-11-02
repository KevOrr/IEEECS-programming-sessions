#!/usr/bin/env python2

num_queries = int(raw_input())

for i in range(num_queries):
    n_points = int(raw_input())
    points = set()
    for j in range(n_points):
        points.add(tuple(int(coord) for coord in raw_input().split()))
    points = list(points)

    if n_points <= 2:
        print 'YES'
        continue

    xs = set(point[0] for point in points)
    ys = set(point[1] for point in points)

    miny, maxy = min(ys), max(ys)
    minx, maxx = min(xs), max(xs)

    vert  = [p for p in points if p[0] == minx or p[0] == maxx]
    horiz = [p for p in points if p[1] == miny or p[1] == maxy]
    edges = vert + horiz

    if any(p not in edges for p in points):
        print 'NO'
        continue

    if all(minx <= p[0] <= maxx for p in horiz) and all(miny <= p[1] <= maxy for p in vert):
        print 'YES'
    else:
        print 'NO'
