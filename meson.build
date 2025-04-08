project(
    'Top Down Shooter',
    'cpp',
    default_options: ['cpp_std=c++17', 'default_library=static'],
)
kraken_dep = dependency('kraken-engine')

inc = include_directories('include')
src = [
    'main.cpp',
    'src/player.cpp',
    'src/bullet.cpp',
    'src/enemy.cpp',
]

executable('app', src, include_directories: inc, dependencies: kraken_dep)