#!/bin/bash
# PINTOS-P1: THREADS -- ITEMIZED TESTING SCRIPT by Brian Sumner 2018


# IMPORTANT NOTE: To allow execution of this script, run the following command:   chmod +x pintos-p1-tests.sh 
# Once you have set execution privileges, run this script:  ./pintos-p1-tests.sh


echo ""
echo ""
echo "PINTOS-P1: THREADS  --  ITEMIZED PASS/FAIL TESTING SCRIPT"
echo ""
echo ""
echo "NOTE: This script must be run from your Pintos 'src/threads/' directory."
echo "NOTE: First, uncomment/comment out specific tests in this script with the # char"
echo ""
echo ""
echo "This script will perform the following tasks:"
echo ""
echo "1.  make clean"
echo "2.  make"
echo "3.  cd build"
echo "4.  *It will then run all tests which are not commented out in this script file*"
echo "5.  cd .."
echo ""
echo ""

read -p "Press the [ENTER] key to continue, or [CTRL]+[C] to abort testing."


# BEGIN SCRIPT:


make clean
make
cd build


# BEGIN TEST SUITE:

# NOTE: TO RUN A TEST, UNCOMMENT BOTH THE 'pintos' LINE AND THE 'perl' LINE


echo ""
echo ""
echo ""
echo "PASS/FAIL TEST:   pintos run alarm-single"
echo ""
#pintos -v -k -T 60 --qemu  -- -q  run alarm-single < /dev/null 2> tests/threads/alarm-single.errors |tee tests/threads/alarm-single.output
echo ""
#perl -I../.. ../../tests/threads/alarm-single.ck tests/threads/alarm-single tests/threads/alarm-single.result


echo ""
echo ""
echo ""
echo "PASS/FAIL TEST:   pintos run alarm-multiple"
echo ""
#pintos -v -k -T 60 --qemu  -- -q  run alarm-multiple < /dev/null 2> tests/threads/alarm-multiple.errors |tee tests/threads/alarm-multiple.output
echo ""
#perl -I../.. ../../tests/threads/alarm-multiple.ck tests/threads/alarm-multiple tests/threads/alarm-multiple.result


echo ""
echo ""
echo ""
echo "PASS/FAIL TEST:   pintos run alarm-simultaneous"
echo ""
#pintos -v -k -T 60 --qemu  -- -q  run alarm-simultaneous < /dev/null 2> tests/threads/alarm-simultaneous.errors |tee tests/threads/alarm-simultaneous.output
echo ""
#perl -I../.. ../../tests/threads/alarm-simultaneous.ck tests/threads/alarm-simultaneous tests/threads/alarm-simultaneous.result


echo ""
echo ""
echo ""
echo "PASS/FAIL TEST:   pintos run alarm-priority"
echo ""
#pintos -v -k -T 60 --qemu  -- -q  run alarm-priority < /dev/null 2> tests/threads/alarm-priority.errors |tee tests/threads/alarm-priority.output
echo ""
#perl -I../.. ../../tests/threads/alarm-priority.ck tests/threads/alarm-priority tests/threads/alarm-priority.result


echo ""
echo ""
echo ""
echo "PASS/FAIL TEST:   pintos run alarm-zero"
echo ""
#pintos -v -k -T 60 --qemu  -- -q  run alarm-zero < /dev/null 2> tests/threads/alarm-zero.errors |tee tests/threads/alarm-zero.output
echo ""
#perl -I../.. ../../tests/threads/alarm-zero.ck tests/threads/alarm-zero tests/threads/alarm-zero.result


echo ""
echo ""
echo ""
echo "PASS/FAIL TEST:   pintos run alarm-negative"
echo ""
#pintos -v -k -T 60 --qemu  -- -q  run alarm-negative < /dev/null 2> tests/threads/alarm-negative.errors |tee tests/threads/alarm-negative.output
echo ""
#perl -I../.. ../../tests/threads/alarm-negative.ck tests/threads/alarm-negative tests/threads/alarm-negative.result


echo ""
echo ""
echo ""
echo "PASS/FAIL TEST:   pintos run priority-change"
echo ""
#pintos -v -k -T 60 --qemu  -- -q  run priority-change < /dev/null 2> tests/threads/priority-change.errors |tee tests/threads/priority-change.output
echo ""
#perl -I../.. ../../tests/threads/priority-change.ck tests/threads/priority-change tests/threads/priority-change.result


echo ""
echo ""
echo ""
echo "PASS/FAIL TEST:   pintos run priority-donate-one"
echo ""
#pintos -v -k -T 60 --qemu  -- -q  run priority-donate-one < /dev/null 2> tests/threads/priority-donate-one.errors |tee tests/threads/priority-donate-one.output
echo ""
#perl -I../.. ../../tests/threads/priority-donate-one.ck tests/threads/priority-donate-one tests/threads/priority-donate-one.result


echo ""
echo ""
echo ""
echo "PASS/FAIL TEST:   pintos run priority-donate-multiple"
echo ""
#pintos -v -k -T 60 --qemu  -- -q  run priority-donate-multiple < /dev/null 2> tests/threads/priority-donate-multiple.errors |tee tests/threads/priority-donate-multiple.output
echo ""
#perl -I../.. ../../tests/threads/priority-donate-multiple.ck tests/threads/priority-donate-multiple tests/threads/priority-donate-multiple.result


echo ""
echo ""
echo ""
echo "PASS/FAIL TEST:   pintos run priority-donate-multiple2"
echo ""
#pintos -v -k -T 60 --qemu  -- -q  run priority-donate-multiple2 < /dev/null 2> tests/threads/priority-donate-multiple2.errors |tee tests/threads/priority-donate-multiple2.output
echo ""
#perl -I../.. ../../tests/threads/priority-donate-multiple2.ck tests/threads/priority-donate-multiple2 tests/threads/priority-donate-multiple2.result


echo ""
echo ""
echo ""
echo "PASS/FAIL TEST:   pintos run priority-donate-nest"
echo ""
#pintos -v -k -T 60 --qemu  -- -q  run priority-donate-nest < /dev/null 2> tests/threads/priority-donate-nest.errors |tee tests/threads/priority-donate-nest.output
echo ""
#perl -I../.. ../../tests/threads/priority-donate-nest.ck tests/threads/priority-donate-nest tests/threads/priority-donate-nest.result


echo ""
echo ""
echo ""
echo "PASS/FAIL TEST:   pintos run priority-donate-sema"
echo ""
#pintos -v -k -T 60 --qemu  -- -q  run priority-donate-sema < /dev/null 2> tests/threads/priority-donate-sema.errors |tee tests/threads/priority-donate-sema.output
echo ""
#perl -I../.. ../../tests/threads/priority-donate-sema.ck tests/threads/priority-donate-sema tests/threads/priority-donate-sema.result


echo ""
echo ""
echo ""
echo "PASS/FAIL TEST:   pintos run priority-donate-lower"
echo ""
#pintos -v -k -T 60 --qemu  -- -q  run priority-donate-lower < /dev/null 2> tests/threads/priority-donate-lower.errors |tee tests/threads/priority-donate-lower.output
echo ""
#perl -I../.. ../../tests/threads/priority-donate-lower.ck tests/threads/priority-donate-lower tests/threads/priority-donate-lower.result


echo ""
echo ""
echo ""
echo "PASS/FAIL TEST:   pintos run priority-fifo"
echo ""
#pintos -v -k -T 60 --qemu  -- -q  run priority-fifo < /dev/null 2> tests/threads/priority-fifo.errors |tee tests/threads/priority-fifo.output
echo ""
#perl -I../.. ../../tests/threads/priority-fifo.ck tests/threads/priority-fifo tests/threads/priority-fifo.result


echo ""
echo ""
echo ""
echo "PASS/FAIL TEST:   pintos run priority-preempt"
echo ""
#pintos -v -k -T 60 --qemu  -- -q  run priority-preempt < /dev/null 2> tests/threads/priority-preempt.errors |tee tests/threads/priority-preempt.output
echo ""
#perl -I../.. ../../tests/threads/priority-preempt.ck tests/threads/priority-preempt tests/threads/priority-preempt.result


echo ""
echo ""
echo ""
echo "PASS/FAIL TEST:   pintos run priority-sema"
echo ""
#pintos -v -k -T 60 --qemu  -- -q  run priority-sema < /dev/null 2> tests/threads/priority-sema.errors |tee tests/threads/priority-sema.output
echo ""
#perl -I../.. ../../tests/threads/priority-sema.ck tests/threads/priority-sema tests/threads/priority-sema.result


echo ""
echo ""
echo ""
echo "PASS/FAIL TEST:   pintos run priority-condvar"
echo ""
#pintos -v -k -T 60 --qemu  -- -q  run priority-condvar < /dev/null 2> tests/threads/priority-condvar.errors |tee tests/threads/priority-condvar.output
echo ""
#perl -I../.. ../../tests/threads/priority-condvar.ck tests/threads/priority-condvar tests/threads/priority-condvar.result


echo ""
echo ""
echo ""
echo "PASS/FAIL TEST:   pintos run priority-donate-chain"
echo ""
#pintos -v -k -T 60 --qemu  -- -q  run priority-donate-chain < /dev/null 2> tests/threads/priority-donate-chain.errors |tee tests/threads/priority-donate-chain.output
echo ""
#perl -I../.. ../../tests/threads/priority-donate-chain.ck tests/threads/priority-donate-chain tests/threads/priority-donate-chain.result


echo ""
echo ""
echo ""
echo "PASS/FAIL TEST:   pintos run mlfqs-load-1"
echo ""
#pintos -v -k -T 480 --qemu  -- -q -mlfqs run mlfqs-load-1 < /dev/null 2> tests/threads/mlfqs-load-1.errors |tee tests/threads/mlfqs-load-1.output
echo ""
#perl -I../.. ../../tests/threads/mlfqs-load-1.ck tests/threads/mlfqs-load-1 tests/threads/mlfqs-load-1.result


echo ""
echo ""
echo ""
echo "PASS/FAIL TEST:   pintos run mlfqs-load-60"
echo ""
#pintos -v -k -T 480 --qemu  -- -q -mlfqs run mlfqs-load-60 < /dev/null 2> tests/threads/mlfqs-load-60.errors |tee tests/threads/mlfqs-load-60.output
echo ""
#perl -I../.. ../../tests/threads/mlfqs-load-60.ck tests/threads/mlfqs-load-60 tests/threads/mlfqs-load-60.result


echo ""
echo ""
echo ""
echo "PASS/FAIL TEST:   pintos run mlfqs-load-avg"
echo ""
#pintos -v -k -T 480 --qemu  -- -q -mlfqs run mlfqs-load-avg < /dev/null 2> tests/threads/mlfqs-load-avg.errors |tee tests/threads/mlfqs-load-avg.output
echo ""
#perl -I../.. ../../tests/threads/mlfqs-load-avg.ck tests/threads/mlfqs-load-avg tests/threads/mlfqs-load-avg.result


echo ""
echo ""
echo ""
echo "PASS/FAIL TEST:   pintos run mlfqs-recent-1"
echo ""
#pintos -v -k -T 480 --qemu  -- -q -mlfqs run mlfqs-recent-1 < /dev/null 2> tests/threads/mlfqs-recent-1.errors |tee tests/threads/mlfqs-recent-1.output
echo ""
#perl -I../.. ../../tests/threads/mlfqs-recent-1.ck tests/threads/mlfqs-recent-1 tests/threads/mlfqs-recent-1.result


echo ""
echo ""
echo ""
echo "PASS/FAIL TEST:   pintos run mlfqs-fair-2"
echo ""
#pintos -v -k -T 480 --qemu  -- -q -mlfqs run mlfqs-fair-2 < /dev/null 2> tests/threads/mlfqs-fair-2.errors |tee tests/threads/mlfqs-fair-2.output
echo ""
#perl -I../.. ../../tests/threads/mlfqs-fair-2.ck tests/threads/mlfqs-fair-2 tests/threads/mlfqs-fair-2.result


echo ""
echo ""
echo ""
echo "PASS/FAIL TEST:   pintos run mlfqs-fair-20"
echo ""
#pintos -v -k -T 480 --qemu  -- -q -mlfqs run mlfqs-fair-20 < /dev/null 2> tests/threads/mlfqs-fair-20.errors |tee tests/threads/mlfqs-fair-20.output
echo ""
#perl -I../.. ../../tests/threads/mlfqs-fair-20.ck tests/threads/mlfqs-fair-20 tests/threads/mlfqs-fair-20.result


echo ""
echo ""
echo ""
echo "PASS/FAIL TEST:   pintos run mlfqs-nice-2"
echo ""
#pintos -v -k -T 480 --qemu  -- -q -mlfqs run mlfqs-nice-2 < /dev/null 2> tests/threads/mlfqs-nice-2.errors |tee tests/threads/mlfqs-nice-2.output
echo ""
#perl -I../.. ../../tests/threads/mlfqs-nice-2.ck tests/threads/mlfqs-nice-2 tests/threads/mlfqs-nice-2.result


echo ""
echo ""
echo ""
echo "PASS/FAIL TEST:   pintos run mlfqs-nice-10"
echo ""
#pintos -v -k -T 480 --qemu  -- -q -mlfqs run mlfqs-nice-10 < /dev/null 2> tests/threads/mlfqs-nice-10.errors |tee tests/threads/mlfqs-nice-10.output
echo ""
#perl -I../.. ../../tests/threads/mlfqs-nice-10.ck tests/threads/mlfqs-nice-10 tests/threads/mlfqs-nice-10.result


echo ""
echo ""
echo ""
echo "PASS/FAIL TEST:   pintos run mlfqs-block"
echo ""
#pintos -v -k -T 480 --qemu  -- -q -mlfqs run mlfqs-block < /dev/null 2> tests/threads/mlfqs-block.errors |tee tests/threads/mlfqs-block.output
echo ""
#perl -I../.. ../../tests/threads/mlfqs-block.ck tests/threads/mlfqs-block tests/threads/mlfqs-block.result

echo ""
echo ""

