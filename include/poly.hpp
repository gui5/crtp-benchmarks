#include <cstdio>
#include <vector>
#include <cstdint>
#include <memory>

namespace poly
{
	class IWidget
	{
	public:
		virtual void draw()noexcept = 0;
		virtual uint64_t compute(uint64_t value)noexcept = 0;

		virtual ~IWidget() = default;
	protected:
		IWidget() = default;

	};

	using WidgetVector = std::vector<std::unique_ptr<IWidget>>;

	class HelloWidget : public IWidget
	{
	public:
		HelloWidget() = default;
		~HelloWidget() = default;

		void draw()noexcept override;
		uint64_t compute(uint64_t value)noexcept override;
	};

	class WorldWidget : public IWidget
	{
	public:
		WorldWidget() = default;
		~WorldWidget() = default;

		void draw()noexcept override;
		uint64_t compute(uint64_t value)noexcept override;
	};


	class SquareWidget : public IWidget
	{
	public:
		SquareWidget() = default;
		~SquareWidget() = default;

		void draw()noexcept override;
		uint64_t compute(uint64_t value)noexcept override;
	};

	class OneWidget : public IWidget
	{
	public:
		OneWidget() = default;
		~OneWidget() = default;

		void draw()noexcept override;
		uint64_t compute(uint64_t value)noexcept override;
	};

	inline void processWidgets(WidgetVector& vec, uint64_t& value)noexcept {
		for (auto& widget : vec)
		{
			value = widget->compute(value);
		}
	}
}