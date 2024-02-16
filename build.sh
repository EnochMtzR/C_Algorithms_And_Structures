cmake -DCMAKE_BUILD_TYPE=Debug -G "Unix Makefiles" -S . -B ./debug

cd debug
make

cp testAlgorithms ../
cp testLists ../
