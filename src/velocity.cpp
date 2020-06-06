#include <iostream>
#include <memory>

#include "Format.h"
#include "color/RGBColor.h"
#include "color/ResetColor.h"
#include "color/TermColor.h"
#include "color/TermColor256.h"
#include "color/visitor/ANSIColorCodeGenerator.h"
#include "color/visitor/ZshColorCodeGenerator.h"
#include "segment/CWDSegment.h"
#include "segment/EndSegment.h"
#include "segment/EnvironmentConditionalSegment.h"
#include "segment/GitInfoSegment.h"
#include "segment/GitRepoConditionalSegment.h"
#include "segment/StartSegment.h"
#include "segment/TextSegment.h"
#include "segment/visitor/EvalVisitor.h"
#include "segment/visitor/ForwardGenerator.h"
#include "segment/visitor/ReverseGenerator.h"
#include "style/BoldStyle.h"
#include "style/DoubleUnderlineStyle.h"
#include "style/FaintStyle.h"
#include "style/ItalicStyle.h"
#include "style/ResetStyle.h"
#include "style/StrikethroughStyle.h"
#include "style/UnderlineStyle.h"
#include "style/visitor/ANSIStyleCodeGenerator.h"
#include "style/visitor/ZshStyleCodeGenerator.h"

using std::cerr;
using std::cout;
using std::endl;
using std::make_shared;
using velocity::color::ANSIColorCodeGenerator;
using velocity::color::RGBColor;
using velocity::color::TermColor;
using velocity::color::TermColor256;
using velocity::color::ZshColorCodeGenerator;
using velocity::segment::CWDSegment;
using velocity::segment::EndSegment;
using velocity::segment::EnvironmentConditionalSegment;
using velocity::segment::EvalVisitor;
using velocity::segment::ForwardGenerator;
using velocity::segment::GitInfoSegment;
using velocity::segment::GitRepoConditionalSegment;
using velocity::segment::ReverseGenerator;
using velocity::segment::StartSegment;
using velocity::segment::TextSegment;
using velocity::style::ANSIStyleCodeGenerator;
using velocity::style::BoldStyle;
using velocity::style::DoubleUnderlineStyle;
using velocity::style::FaintStyle;
using velocity::style::ItalicStyle;
using velocity::style::ResetStyle;
using velocity::style::StrikethroughStyle;
using velocity::style::UnderlineStyle;
using velocity::style::ZshStyleCodeGenerator;

#include <chrono>

auto term_brcyan = make_shared<TermColor>("brcyan");
auto term_black  = make_shared<TermColor>("black");
auto term_blue   = make_shared<TermColor>("blue");
auto term_green  = make_shared<TermColor>("green");
auto term_yellow = make_shared<TermColor>("yellow");
auto term_red    = make_shared<TermColor>("red");

auto bold_style             = make_shared<BoldStyle>();
auto faint_style            = make_shared<FaintStyle>();
auto italic_style           = make_shared<ItalicStyle>();
auto underline_style        = make_shared<UnderlineStyle>();
auto double_underline_style = make_shared<DoubleUnderlineStyle>();
auto strikethrough_style    = make_shared<StrikethroughStyle>();
auto reset_style            = make_shared<ResetStyle>();

auto ansi_color_code_generator = make_shared<ANSIColorCodeGenerator>();
auto ansi_style_code_generator = make_shared<ANSIStyleCodeGenerator>();

auto zsh_color_code_generator = make_shared<ZshColorCodeGenerator>();
auto zsh_style_code_generator = make_shared<ZshStyleCodeGenerator>();

auto normal_style = vector<shared_ptr<Style>>();

void prompt_forward() {
    auto cwd_format          = make_shared<Format>(term_black, term_blue, normal_style);
    auto git_clean_format    = make_shared<Format>(term_black, term_green, normal_style);
    auto git_dirty_format    = make_shared<Format>(term_black, term_yellow, normal_style);
    auto git_detached_format = make_shared<Format>(term_black, term_red, normal_style);

    auto start       = make_shared<StartSegment>();
    auto cwd         = make_shared<CWDSegment>(cwd_format, 0, "", "");
    auto in_git_repo = make_shared<GitRepoConditionalSegment>();
    auto git         = make_shared<GitInfoSegment>(
        git_clean_format, git_dirty_format, git_detached_format, 0, "➦", "", "±", "");
    auto end = make_shared<EndSegment>();

    in_git_repo->set_true_segment(git);
    in_git_repo->set_false_segment(end);

    start->set_next(cwd);
    cwd->set_prev(start);
    cwd->set_next(in_git_repo);
    in_git_repo->set_prev(cwd);
    in_git_repo->set_next(git);
    git->set_prev(in_git_repo);
    git->set_next(end);
    end->set_prev(end);

    EvalVisitor e;
    start->accept(e);

    /* ForwardGenerator p(ansi_color_code_generator, ansi_style_code_generator); */
    ForwardGenerator p(zsh_color_code_generator, zsh_style_code_generator);

    start->accept(p);
    cout << p.text();
}

int main() {
    auto a = std::chrono::high_resolution_clock::now();

    prompt_forward();

    auto   b          = std::chrono::high_resolution_clock::now();
    double time_taken = std::chrono::duration_cast<std::chrono::microseconds>(b - a).count();
    cerr << time_taken << " us" << endl;
    return 0;
}
