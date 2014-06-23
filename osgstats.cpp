#include <iostream>
#include <osgDB/ReadFile>
#include <osgUtil/Statistics>

int main(int argc, char* argv[])
{
    if(argc != 2) {
        std::cerr << "Usage: " << argv[0] << " file.osg" << std::endl;
        return 1;
    }

    osg::ref_ptr<osg::Node> node = osgDB::readNodeFile(argv[1]);

    osgUtil::StatsVisitor stats;
    node->accept(stats);
    stats.totalUpStats();
    stats.print(std::cout);

    return 0;
}