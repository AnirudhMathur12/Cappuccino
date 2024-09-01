#include <string>

namespace n_CompileLinkTools
{

class CompileLinkTools
{
public:
    CompileLinkTools(const CompileLinkTools&) = delete;
    CompileLinkTools& GetInstance();

    void compile_asm(std::string filename);

private:
    CompileLinkTools();
};

}  // namespace n_CompileLinkTools
