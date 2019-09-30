#include "jpk_matrix.h"
#include "vec2f.h"
#include <vector>

namespace jpk {
class mat2f : public jpk_matrix
{
public:
    mat2f(std::vector<vec2f> &cols)
    {
        columns = cols;
    };

    ~mat2f()
    {

    };

    mat2f operator+(mat2f& mat_b)
    {
        
        mat2f mat_c()
        
    };

    void add_col(vec2f& vec)
    {
        columns.push_back(vec);
    };

    void rm_col()
    {
        columns.pop_back();
    };

    void rm_col(int c)
    {
        columns.erase(columns.begin() + c);
    }
    

    void set_col(unsigned int c, vec2f &vec)
    {
        columns.assign(c, vec);
    };

private: 
    std::vector<vec2f> columns;





};
};