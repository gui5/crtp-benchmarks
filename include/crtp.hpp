
#include <cstdio>
#include <variant>
#include <vector>

namespace crtp
{
	template <typename WidgetImpl>
	struct Widget {
		void draw() noexcept { static_cast<WidgetImpl&>(*this).draw(); }
		uint64_t compute(uint64_t value)noexcept { return static_cast<WidgetImpl&>(*this).compute(value); }

	private:
		Widget() = default;
		friend WidgetImpl;
	};

	struct HelloWidget : Widget<HelloWidget> {
		HelloWidget() = default;
		void draw() noexcept { printf("Hello\n"); }
		uint64_t compute(uint64_t value) noexcept { return value++; }
	};

	struct WorldWidget : Widget<WorldWidget> {
		WorldWidget() = default;
		void draw() noexcept { printf("World\n"); }
		uint64_t compute(uint64_t value) noexcept { return value += 2; }
	};

	struct SquareWidget : Widget<SquareWidget>
	{
		SquareWidget() = default;
		void draw() noexcept { printf("Squre\n"); }
		uint64_t compute(uint64_t value) noexcept { return value * value; }
	};

	struct OneWidget : Widget<OneWidget>
	{
		OneWidget() = default;
		void draw() noexcept { printf("One\n"); }
		uint64_t compute(uint64_t value) noexcept { return 1; }
	};


	using WidgetVector = std::vector<std::variant<HelloWidget, WorldWidget, SquareWidget, OneWidget>>;

	void processWidgets(WidgetVector& vec, uint64_t& value)noexcept {
		for (auto& widget : vec)
		{
			std::visit([&value](auto& impl) {value = impl.compute(value); },widget);
		}
	}

}

