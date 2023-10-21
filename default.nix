with import <nixpkgs> {};
stdenv.mkDerivation {
  name = "makelink";
  version = "1.0";
  src = ./.;
  buildInputs = [ gcc ];
  nativeBuildInputs = [ cmake ];

  configurePhase = ''
  mkdir -p build
  cd build
  cmake ..
  '';

  buildPhase = ''
  make
  '';

  installPhase = ''
  mkdir $out
  mv makelink $out/makelink
  '';
}
