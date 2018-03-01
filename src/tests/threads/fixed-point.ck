# -*- perl -*-
use strict;
use warnings;
use tests::tests;
check_expected ([<<'EOF']);
(fixed-point) begin
(fixed-point) fix = 10
(fixed-point) fix to int floor is 10
(fixed-point) fix to int round is 10
(fixed-point) decimal value: 10
(fixed-point) subtracted 6 (int)
(fixed-point) added 1 (int)
(fixed-point) decimal value: 5
(fixed-point) divided by 3 (int)
(fixed-point) fix to int floor is 1
(fixed-point) fix to int round is 2
(fixed-point) multiplied by 3 (int)
(fixed-point) decimal value: 5
(fixed-point) end
EOF
pass;
