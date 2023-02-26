#include <map>
#include <nlohmann/json.hpp>
#include <vector>

using json = nlohmann::json;


/**
 * @brief A class to encapsulate and use json tools methods.
 */
class JsonTools
{
  public:
    JsonTools()           = delete;
    ~JsonTools() noexcept = delete;

    JsonTools(const JsonTools& other)                = default;
    JsonTools(JsonTools&& other) noexcept            = default;
    JsonTools& operator=(const JsonTools& other)     = delete;
    JsonTools& operator=(JsonTools&& other) noexcept = delete;

    [[nodiscard]] static json getGroupFromFile(std::string filePath);

  protected:
  private:
};
