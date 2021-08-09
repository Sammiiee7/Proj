#!/bin/sh

set -v

./poly_class << EOF
2
3 2 1
2
2 3 4
-1 1
-1 2
3
2 
2
3 2 2
2
2 3 4
EOF

./poly_class << EOF
2
3 2 3
3
3 4 5 6
-1 1
-1 2
4 
5 
2
3 2 3
3
3 4 5 6
EOF

