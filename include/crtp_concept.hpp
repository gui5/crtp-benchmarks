
#include <concepts>
#include <variant>
#include <vector>
#include <cstdint>

namespace crtp_concept
{
	template<typename WidgetImpl>
	concept Widget = requires(WidgetImpl widget)
	{
		{widget.draw()}noexcept -> std::same_as<void>;
		{widget.compute(uint64_t{})}noexcept -> std::same_as<uint64_t>;
	};

	template <Widget WidgetImpl>
	struct WidgetBase : WidgetImpl {};

	struct HelloWidgetImpl {
		void draw()noexcept { printf("Hello\n"); }
		uint64_t compute(uint64_t value)noexcept { return value++; }
	};

	struct WorldWidgetImpl {
		void draw()noexcept { printf("World\n"); }
		uint64_t compute(uint64_t value)noexcept { return value += 2; }
	};

	struct SquareWidgetImpl {
		void draw()noexcept { printf("Square\n"); }
		uint64_t compute(uint64_t value)noexcept { return value * value; }
	};

	struct OneWidgetImpl {
		void draw()noexcept { printf("One\n"); }
		uint64_t compute(uint64_t value)noexcept { return 1; }
	};

	using HelloWidget = WidgetBase<HelloWidgetImpl>;
	using WorldWidget = WidgetBase<WorldWidgetImpl>;
	using SquareWidget = WidgetBase<SquareWidgetImpl>;
	using OneWidget = WidgetBase<OneWidgetImpl>;

	using WidgetVector = std::vector<std::variant<HelloWidget,WorldWidget,SquareWidget, OneWidget>>;

	void processWidgets(WidgetVector& vec, uint64_t& value)noexcept {
		for (auto& widget : vec)
		{
			std::visit([&value](auto& impl) {value = impl.compute(value); }, widget);
		}
	}
} 