#pragma once

// We need it to fix encoding problems in generated files
#undef wxT
#define wxT(str) wxString::FromUTF8(str)