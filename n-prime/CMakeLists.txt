cmake_minimum_required(VERSION 3.28)

# =================================================================================================

project(TemplatesAbuse-n-prime
    LANGUAGES CXX
    VERSION 1.1
)

# =================================================================================================

if (NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 20)
else()
  if (CMAKE_CXX_STANDARD LESS 20)
    message(FATAL_ERROR "CMAKE_CXX_STANDARD requires to be greater or equal than 20, but given ${CMAKE_CXX_STANDARD}")
  endif(CMAKE_CXX_STANDARD LESS 20)
endif()

set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

# =================================================================================================

set(TEMPLATES_ABUSE_N_PRIME_RUN ${PROJECT_SOURCE_DIR}/src/print-n-prime.sh)

set(TEMPLATES_ABUSE_N_PRIME_RUN_IN ${PROJECT_SOURCE_DIR}/src/print-n-prime.sh.in)
set(TEMPLATES_ABUSE_N_PRIME_RUN_OUT ${CMAKE_BINARY_DIR}/print-n-prime)

# =================================================================================================

configure_file(
  ${TEMPLATES_ABUSE_N_PRIME_RUN_IN}
  ${TEMPLATES_ABUSE_N_PRIME_RUN_OUT}
  @ONLY
)

file(CHMOD ${TEMPLATES_ABUSE_N_PRIME_RUN_OUT} PERMISSIONS OWNER_READ OWNER_EXECUTE)
file(CHMOD ${TEMPLATES_ABUSE_N_PRIME_RUN}     PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE)

# =================================================================================================

# =================================================================================================

function(add_n_prime_test n_prime expected_value)
  message("КАКИЕ НАХУЙ ГОСУСЛУГИ")
  add_test(
    NAME template-abuse::n-prime::${n_prime}
    COMMAND bash -c "${TEMPLATES_ABUSE_N_PRIME_RUN_OUT} ${n_prime} | grep -q ${expected_value}"
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
  )
endfunction(add_n_prime_test)

add_n_prime_test(0 2)
add_n_prime_test(1 3)
add_n_prime_test(2 5)
add_n_prime_test(3 7)
add_n_prime_test(4 11)
add_n_prime_test(5 13)
add_n_prime_test(6 17)
add_n_prime_test(7 19)
add_n_prime_test(8 23)
add_n_prime_test(9 29)
add_n_prime_test(10 31)
add_n_prime_test(11 37)
add_n_prime_test(12 41)
add_n_prime_test(13 43)
add_n_prime_test(14 47)
add_n_prime_test(15 53)
add_n_prime_test(16 59)
add_n_prime_test(17 61)
add_n_prime_test(18 67)
add_n_prime_test(19 71)
add_n_prime_test(20 73)
add_n_prime_test(21 79)
add_n_prime_test(22 83)
add_n_prime_test(23 89)
add_n_prime_test(24 97)
add_n_prime_test(25 101)
add_n_prime_test(26 103)
add_n_prime_test(27 107)
add_n_prime_test(28 109)
add_n_prime_test(29 113)
add_n_prime_test(30 127)
add_n_prime_test(31 131)
add_n_prime_test(32 137)
add_n_prime_test(33 139)
add_n_prime_test(34 149)
add_n_prime_test(35 151)
add_n_prime_test(36 157)
add_n_prime_test(37 163)
add_n_prime_test(38 167)
add_n_prime_test(39 173)
add_n_prime_test(40 179)
add_n_prime_test(41 181)
add_n_prime_test(42 191)
add_n_prime_test(43 193)
add_n_prime_test(44 197)
add_n_prime_test(45 199)
add_n_prime_test(46 211)
add_n_prime_test(47 223)
add_n_prime_test(48 227)
add_n_prime_test(49 229)
add_n_prime_test(50 233)
add_n_prime_test(51 239)
add_n_prime_test(52 241)
add_n_prime_test(53 251)
add_n_prime_test(54 257)
add_n_prime_test(55 263)
add_n_prime_test(56 269)
add_n_prime_test(57 271)
add_n_prime_test(58 277)
add_n_prime_test(59 281)
add_n_prime_test(60 283)
add_n_prime_test(61 293)
add_n_prime_test(62 307)
add_n_prime_test(63 311)
add_n_prime_test(64 313)
add_n_prime_test(65 317)
add_n_prime_test(66 331)
add_n_prime_test(67 337)
add_n_prime_test(68 347)
add_n_prime_test(69 349)
add_n_prime_test(70 353)
add_n_prime_test(71 359)
add_n_prime_test(72 367)
add_n_prime_test(73 373)
add_n_prime_test(74 379)
add_n_prime_test(75 383)
add_n_prime_test(76 389)
add_n_prime_test(77 397)
add_n_prime_test(78 401)
add_n_prime_test(79 409)
add_n_prime_test(80 419)
add_n_prime_test(81 421)
add_n_prime_test(82 431)
add_n_prime_test(83 433)
add_n_prime_test(84 439)
add_n_prime_test(85 443)
add_n_prime_test(86 449)
add_n_prime_test(87 457)
add_n_prime_test(88 461)
add_n_prime_test(89 463)
add_n_prime_test(90 467)
add_n_prime_test(91 479)
add_n_prime_test(92 487)
add_n_prime_test(93 491)
add_n_prime_test(94 499)
add_n_prime_test(95 503)
add_n_prime_test(96 509)
add_n_prime_test(97 521)
add_n_prime_test(98 523)
add_n_prime_test(99 541)
