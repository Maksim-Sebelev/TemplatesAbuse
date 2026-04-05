#pragma one

//--------------------------------------------------------------------------------------------------------

#include <type_traits>

//--------------------------------------------------------------------------------------------------------
namespace templates_abuse
{
//--------------------------------------------------------------------------------------------------------

using natural_number_t = long unsigned int;

//--------------------------------------------------------------------------------------------------------
namespace __detail
{
//--------------------------------------------------------------------------------------------------------

template <natural_number_t N, natural_number_t H = 2>
struct is_prime :
    public std::bool_constant
            <
                std::conditional_t
                <
                    (H * H > N),
                    std::true_type,
                    std::conditional_t
                    <
                        (N % H == 0),
                        std::false_type,
                        is_prime<N, H + 1>
                    >
                >{}
            >
{};

//--------------------------------------------------------------------------------------------------------

template <>
struct is_prime<0> : public std::false_type {};

//--------------------------------------------------------------------------------------------------------

template <>
struct is_prime<1> : public std::false_type {};

//--------------------------------------------------------------------------------------------------------

template <natural_number_t N, natural_number_t NUMBER_IT = 2, natural_number_t PRIME_IT = 0, bool IS_PRIME_NOW = is_prime<NUMBER_IT>::value>
struct n_prime_ : std::integral_constant
                <
                    natural_number_t,
                    std::conditional_t
                    <
                        (N == PRIME_IT && IS_PRIME_NOW),
                        std::integral_constant<natural_number_t, NUMBER_IT>,
                        n_prime_<N, NUMBER_IT + 1, PRIME_IT + IS_PRIME_NOW>
                    >{}
                >
{};

//--------------------------------------------------------------------------------------------------------
} /* namespace __detail */
//--------------------------------------------------------------------------------------------------------

template <natural_number_t N>
constexpr inline natural_number_t n_prime = __detail::n_prime_<N>::value;

//--------------------------------------------------------------------------------------------------------
} /* namespace templates_abuse */
//--------------------------------------------------------------------------------------------------------
