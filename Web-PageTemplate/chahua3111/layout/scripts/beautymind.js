winWid = 0;

// js for "Safari Apple browser"
function scaleFixHuck(){
	var viewportmeta = document.querySelector && document.querySelector('meta[name="viewport"]'),
	ua = navigator.userAgent,
	gestureStart = function () {
		viewportmeta.content = "width=device-width, minimum-scale=0.25, maximum-scale=1.6";
	},
	scaleFix = function () {
	  if (viewportmeta && /iPhone|iPad/.test(ua) && !/Opera Mini/.test(ua)) {
		viewportmeta.content = "width=device-width, minimum-scale=1.0, maximum-scale=1.0";
		document.addEventListener("gesturestart", gestureStart, false);
	  }
	};
}
// animate social links
function topLinks(slc){
	if($(slc+' a img').size()){
		$(slc+' a img').each(function(index, element) {
			if($(this).attr('lowsrc')!=''){$(this).addClass('soc-img').parent().addClass('soc-ico').append('<img src="'+$(this).attr('data-icon')+'" alt="" class="soc-img-colored">');}
			if($(this).attr('alt')!=''){$(this).parent().append('<span class="title-text"><b>'+$(this).attr('alt')+'</b></span>');}
		});
	}
	$('.wrapper').click(function(e) {
		$('.sign-popup').removeClass('active');
	})
	$('.sign-popup').click(function(e) {
		e.stopPropagation();
	});
	$('.toggle-sign').click(function(e) {
		$($(this).attr('href')).toggleClass('active');
		return false;
	});
	$('.toggle-upper').click(function(e) {
		$($(this).attr('href')).stop(true,false);
		$(this).hasClass('close') ? (tU=-1200,t=2500) : (tU=0,t='slow');
		$($(this).attr('href')).toggleClass('op').animate({top:tU},t);
		return false;
	});
}

// animate scroll 
function backtop(){
	$('.backtop').hover(function(){
			$(this).stop(true,true).fadeTo(0,0.5).fadeTo(300,1);})
		.click(function(e){
			$('html, body').animate({scrollTop:0}, 500);
			return false;
		});
}

// animate menu
function mainMenu(mm){
	// generate <a> classes
	$(mm+' > li').addClass('hovers-a');
	$(mm+' a.active').parent().addClass('active');
	$(mm+' > li > ul > li').addClass('hovers-aa');
	// hover main links 
	$('.hovers-a:not(.active)').hover(function(e){if(!$('.navi-to').hasClass('open')){$(this).find('a:eq(0)').stop(true,true).css('background-position','50% 15px').animate({backgroundPosition: '50% 0'},200);};})
		.mouseleave(function(e) {if(!$('.navi-to').hasClass('open')){$(this).find('a:eq(0)').stop(true,true).animate({backgroundPosition: '50% 10px'},200).animate({backgroundPosition: '50% 100px'},0);}; })
		/*
	$('.hovers-a a').click(function(e){
		if($(this).next('ul').size()) {	return false;}
	});
	*/
	// hover sub links 
	/*$('a.hovers-aa:not(.active)').mouseover(function(e){$(this).stop(true,true).css('background-position','-300px 0').animate({backgroundPosition: '0 0'},300);})
		.mouseleave(function(e) {$(this).stop(true,true).animate({backgroundPosition: '-300px 0'},150); });
	*/
		
	// hover li and show sub menu
	$(mm+' li').hover(
		function(){$(this).find('ul:first').fadeIn(300);},
		function(){$(this).find('ul:first').hide();}
	);
	
	// show menu on width 420 & 300 
	$('html').click(function() {
		if($('.navi-to').hasClass('open')){
			$('.navi-to').click();
		}
	});
	$('.navi-to').click(function(event){
		event.stopPropagation();
		//$(mm).stop(true,true).slideToggle('fast');
		$(mm).toggle();
		$(this).toggleClass('open');
	});
	// back menu on width 768 and 960
	$(window).resize(function(e){
		if(winWid>420){$(mm).show();}
		else {$(mm).hide();$('.navi-to').removeClass('open');}
	});
}

// main slider
function mainSlider(s,AutoS){
	sLi=$(s+' li');
	sLiN=sLi.size();
	if(sLiN>1){
		sw=Math.ceil(99.9/sLiN);
		sIco='';
		spWid=sLi.width()/sLiN;
		for(i=1;i<=sLiN;i++){
			sIco=sIco+'<a href="'+i+'" sNum="'+i+'" class="'+(i==1 ? ' active' : '')+'" style="left:'+(sw*(i-1))+'%" />';
		}
		// generate navi 
		$(s).append('<a href="#" id="slider-left"></a><a href="#" id="slider-right"></a><div id="slider-middle-navi">'+sIco+'</div><div id="slider-bottom-navi">'+sIco+'<span style="width:'+sw+'%;"/></div>');
		$('#slider-bottom-navi a').width(sw+'%');
		sSpan=$('#slider-bottom-navi span');
				
		// fade toggle navi 
		$('#slider-middle-navi, #slider-left, #slider-right').fadeOut(0);
		$(s).mouseover(function(){$('#slider-middle-navi, #slider-left, #slider-right').stop(true,true).fadeIn('fast');})
			.mouseleave(function(){$('#slider-middle-navi, #slider-left, #slider-right').stop(true,true).fadeOut('fast');})
		
		if(AutoS){
			autoSlider=setTimeout(function(){
				$('#slider-right').click();
			},5000);
		}
		
		// click event 
		$('#slider-middle-navi a, #slider-bottom-navi a').click(function(e) {
			// autoSlideshow
			if(AutoS){
				clearTimeout(autoSlider);
				autoSlider=setTimeout(function(){
					$('#slider-right').click();
				},5000);
			}
			// do it )
			if(!$(this).hasClass('active')){
				$('#slider-middle-navi a.active, #slider-bottom-navi a.active').removeClass('active');
				sNum=$(this).attr('sNum')-1;
				$('#slider-middle-navi a:eq('+sNum+'),  #slider-bottom-navi a:eq('+sNum+')').addClass('active');
				lUl=(-100)*sNum;
				lSp=sw*sNum;
				$(s+' ul').stop(true,false).animate({left:lUl+'%'},'easeOutCubic');
				sSpan.stop(true,false).animate({left:lSp+'%'})
			}
			return false;
		});
		$('#slider-left').click(function(e){
			if($('#slider-middle-navi a.active').prev().size())	$('#slider-middle-navi a.active').prev().click();
			else $('#slider-middle-navi a:last').click();
			return false;
		});
		$('#slider-right').click(function(e){
			if($('#slider-middle-navi a.active').next().size())	$('#slider-middle-navi a.active').next().click();
			else $('#slider-middle-navi a:first').click();
			return false;
		});	
	}
}
// recent post list
function listRec(hLi,hBox,hTit){
	if($(hLi).size()){
		sT='';
		$(hLi).find(hBox).animate({top:0},0,'easeOutCubic').animate({top:'100%'},0);
		$(hLi).each(function(index, element) {
			$(element).find(hTit).clone().prependTo($(element).find(hBox));
		}).hover(function(e) {
			hB=$(this).find(hBox);
			hB.find('.rec_fade_context_arrow').css('background-position','center 0');
			hB.find('p').css('opacity',0);
			hB.find('h5').stop().css('opacity',1);
			hB.find('.ico_link').css('opacity',0);
			hB.stop().css('border-top-width','1px').animate({top:0},500,'easeOutCubic');
			sT=setTimeout(function(){
				hB.find('p').animate({opacity:1});
				hB.find('.ico_link').animate({opacity:1});
			},300);
		}).mouseleave(function(e) {
			clearTimeout(sT);
			hB=$(this).find(hBox);
			hB.find('h5').animate({opacity:0});
			hB.find('.rec_fade_context_arrow').css('background-position','0 -100px');
			hB.stop().css('border-top-width','0').animate({top:'100%'},800);
		});
	}
}
// hover box
function overBg(oBg){
	if($(oBg).size()){$(oBg).parent().hover(function(){$(this).find(oBg).stop(true,true).fadeToggle();});}
}

function rem(t){
	$(t).removeClass('active');
	$($(t).attr('href')).stop(true,true).slideUp('fast','linear');
}

// toggle box 
function toggleBox(lnk){
	if($(lnk).size()){
		$(lnk).each(function(index, element) {
			b=$($(this).attr('href'));
			b.height(b.height());
			if(!$(this).hasClass('active'))b.slideUp(0);
		});
		$(lnk).click(function(e) {
			if($(this).hasClass('active')){
				rem(this);
			}
			else{
				Prev=$(lnk+'[rel='+$(this).attr('rel')+'].active');				
				rem(Prev);
				
				$(this).addClass('active');
				$($(this).attr('href')).stop(true,true).slideDown('fast','linear');
			}
			return false;
		});
	}
}
// function testimonials
var autoTest;
function testimonials(te,nav,au,nm){
	teN=Math.ceil($(te+' li').size()/nm)-1;
	if(teN>0){
		UL=$(te+' ul');
		UL.attr('act','0');
		$(nav).html('<a href="prev" class="t-navi-prev" onclick="subslide('+au+',\'prev\',\''+te+'\',\''+nm+'\'); return false;" /><a href="next" class="t-navi-next" onclick="subslide('+au+',\'next\',\''+te+'\',\''+nm+'\'); return false;"/>');
		if(au){
			autoTest=setTimeout(function(){
				$('#t-navi-next').click();
			},5000);
		}
	}
}
function subslide(au,type,te,nm){	
	var UL=$(te+' ul');
	var c=UL.attr('act');
	if(nm==1 || $('body').hasClass('mobile')){mn=1;}
	else if($('body').hasClass('desktop') || $('body').hasClass('tablet')){mn=nm;}
	else {mn=nm/2;}
	
	var teN=Math.ceil($(te+' li').size()/mn)-1;	
	//type =='next' ? c<teN ? c++ : c=0 : c>0 ? c-- : c=teN;
	type =='next' ? c<teN ? c++ : c=c : c>0 ? c-- : c=c;
	
	UL.attr('act',c).stop(true,false).animate({left:'-'+c+'00%'},500);
	if(au){
		clearTimeout(autoTest);
		autoTest=setTimeout(function(){
			$('.t-navi-next').click();
		},5000);
	}
	if(nm>1){
		$(window).resize(function(e) {
			UL.attr('act',0).stop(true,false).animate({marginLeft:0});
		});
	}
}

/* toggles horizontal filtr */
$.fn.slideHorzShow = function(speed, easing, callback ) { this.animate( { /*marginLeft : 'show', marginRight : 'show',*/ paddingLeft : 'show', paddingRight : 'show', width : 'show' }, speed, easing, callback ); };
$.fn.slideHorzHide = function(speed, easing, callback ) { this.animate( { /*marginLeft : 'hide', marginRight : 'hide',*/ paddingLeft : 'hide', paddingRight : 'hide', width : 'hide' }, speed, easing, callback ); };

function toggHor(){
	wWid=$('.container').width();
	if(wWid>760) $('#filter-cats a:not(.active)').slideHorzHide(0);
	
	$(window).resize(function(e) {
		wWid=$('.container').width();
		wWid<768 ? $('#filter-cats a').slideHorzShow(0) : $('#filter-cats a:not(.active)').slideHorzHide(0);
		$('#filtr-ico').removeClass('active');
	});
	$('.filtr-block').hover(
		function(){if(wWid>959){$('#filter-cats').addClass('opencats').find('a').stop(true,true).slideHorzShow(300,'linear');}},
		function(){if(wWid>959){$('#filter-cats').removeClass('opencats').find('a:not(.active)').slideHorzHide(150,'linear');}
	});
	$('#filtr-ico').click(function(e){
		$(this).hasClass('active') ? $('#filter-cats').removeClass('opencats').find('a:not(.active)').slideHorzHide(300,'linear') : $('#filter-cats').addClass('opencats').find('a').slideHorzShow(150,'linear');
		$(this).toggleClass('active');
		return false;
	});
	
	
	$('#filter-cats a').click(function(e) {
		if(!$(this).hasClass('active')){
			$('#filter-cats a.active').removeClass('active');
			$(this).addClass('active').animate({paddingLeft:0});
		}
	});
	
	
	
	
}
// tabs 
function tabNavi(tab){
	if($(tab+' .has-submenu a').size()){
		$('.wrapper').click(function(e) {
			$(tab+' li.has-submenu ul').hide();
		});
		$(tab+' li.has-submenu > a').addClass('submn').click(function(e) {
			e.stopPropagation();
			$(this).parent().find('ul').toggle();			
			return false;
		});
		$(tab+' a:not(.submn)').click(function(e) {
			if(!$(this).hasClass('active')){
				p=$(this).parents(tab).find('a.active').removeClass('active').attr('href');
				$(this).parents(tab).find('a.active-trail').removeClass('active-trail');
				$(this).parents(tab).find('li ul').hide();
				$(p).hide()
				$($(this).addClass('active').attr('href')).show();
				
				$(this).parents('li.has-submenu').find('a.submn').addClass('active-trail');
			}
			return false;
		});		
	}
}

function closeNote(a,b){
	if($(a).size()){
		$(a).click(function(e) {
			$(this).parent(b).fadeOut();
			return false;
		});
	}
}

// accordation 
function accordation(b,bb,bbb,a){
	$(a).click(function(e){
		if($(this).hasClass('active')){
			$(this).removeClass('active').parents(bb).find(bbb).stop(true,true).slideUp(500,'easeOutQuad');
		}
		else{
			$(this).parents(b).find(a+'.active').removeClass('active').parents(bb).find(bbb).stop(true,true).slideUp(500,'easeOutQuad');			
			$(this).addClass('active').parents(bb).find(bbb).stop(true,true).slideDown(500,'easeOutQuad');
		}
		return false;
	});
	$(b).each(function(index, element) {
		ax=$(element).find(a+'.active');
		//if(!ax.size()){ax=$(element).find(a).eq(0).addClass('active');}
		ax.parents(bb).find(bbb).slideDown(0);
	});
}
// toggle 
function toggle(b,bb,a){
	if($(b).size()){
		$(a+':not(.active)').parents(b).find(bb).hide(0);
		
		$(a).click(function(e) {
			$(this).toggleClass('active');
			$(this).parents(b).find(bb).stop(true,true).slideToggle(500,'easeOutQuad');
			return false;
		});
	}
	
}


// gallery
function portfolioDetail(g){
	if($(g+' li').size()>1){
		$(g).each(function(index, element) {
			n=$(element).find('li').size()-1;
			if(n>0)$(element).append('<a href="Previous" class="gnavi gn-prev"><span/></a><a href="Next" class="gnavi gn-next"><span/></a>').attr('current',0).attr('nums',n)
		});
		$('.gnavi').click(function(e) {
			gC=$(this).parent(g);
			p=parseInt(gC.attr('current'));
			n=parseInt(gC.attr('nums'));
			if($(this).hasClass('gn-prev')){
				p<n ? c=p+1 : c=0;
			}
			else{
				p>0 ? c=p-1 : c=n;
			}
			
			gC.find('li:eq('+p+')').stop(true,true).fadeOut('slow','swing');
			gC.attr('current',c).find('li:eq('+c+')').stop(true,true).fadeIn('slow','swing');
			
			return false;
		});
		
	}
}

// post  slider
function postSlider(Post){
	if($(Post).size()){
		$(Post).each(function(index, element) {
			pN=$(element).find('a').size()-1;
			if(pN>0){
				$(element).attr('cur',0).attr('nums',pN).find('a').addClass('itemP');
				$(element).append('<a href="Prev" class="post-navi prev"/><a href="Next" class="post-navi next"/>')
			}
		});
		$('.post-navi').click(function(e) {
			parB=$(this).parent();
			c=parB.attr('cur');
			n=parB.attr('nums');
			prev=c;
			$(this).hasClass('next') ? c<n ? c++ : c=0 : c>0 ? c-- : c=n;
			parB.attr('cur',c).find('.itemP').stop(true,true).eq(prev).fadeOut(1000);
			parB.find('.itemP').eq(c).fadeIn(1000);
			return false;
		});
	}
}

// slider slogan 
function slogansLider(b){
	if($(b+' li').size()>1){
		$(b).after('<a href="Prev" class="sloganNavi prev"/><a href="Next" class="sloganNavi next"/>');
		curSlogan=0;
		maxSlogan=$(b+' li').size()-1;
		autoSlogan = setTimeout(function(){$('.sloganNavi.next').click();},8000);
		$('.sloganNavi').click(function(e) {
			clearTimeout(autoSlogan);
			autoSlogan = setTimeout(function(){$('.sloganNavi.next').click();},8000);
			$(this).has('next') ? curSlogan<maxSlogan ? curSlogan++ : curSlogan=0 : curSlogan>0 ? curSlogan-- : curSlogan=maxSlogan;			
			$(b+' ul').stop(true,false).animate({left:(curSlogan*(-100))+'%'})
			return false;
		});
	}
}

function tdDescription(d){
	if($(d).size()){
		$(d).each(function(index, element) {
			t=$(element).attr('title');
			if(t){
				$(element).removeAttr('title');
				$(element).append('<div class="desc-container-box">'+t+'<i class="deArr"/></div>');
			}
		});
	}
}

// comments 
function comments(){
	$('.comment-item .comment-item:has(div.comment-item)').addClass('has-sub');
	$('.comment-item .comment-item:not(.has-sub):last-child').prepend('<div class="comment-line-hide"/>');
	$('.comment-item .comment-item:not(.has-answer)').prepend('<div class="comment-line"/>');
}


// home slider
function homeSlider(hS,hSP,hSN){
	var hSN_li_Num = $(hSN+' > ul > li').size();
	var hsC=0;
	var hsN=hSN_li_Num-3;
	var TimeS;
	var hsH=-119;
	$('body').hasClass('desktop') || $('body').hasClass('tablet') ? hsH=0-119 : $('body').hasClass('iphone') ? hsH=0-55 : hsH=0-39;
	if(hSN_li_Num>1){
		$(hSN+' > ul > li').each(function(index, element) {$(element).attr('eq',index);});
		$(hSN+' > ul > li > a').click(function(e) {
			clearTimeout(TimeS);
			$(hSP+' .hm-text,'+hSP+' img').stop(true,true);
			$(hSP+' .hm-text:not(:first),'+hSP+' img:not(:first)').remove();
			$(hSP).prepend('<img src="'+$(this).attr('href')+'"><div class="hm-text">'+$(this).parent('li').find('.hm-text').html()+'</div>');
			
			TimeS=setTimeout(function(){
				$(hSP+' .hm-text:last, '+hSP+' img:last').animate({opacity:0},400);
				k=Number($(this).parent('li').attr('eq'))-1;
				if(k<hsN && k>0){$(hSN+' > ul').stop(true,false).animate({top:hsH*k},400); hsC=k;}
				setTimeout(function(){
					$(hSP+' .hm-text:not(:first),'+hSP+' img:not(:first)').remove();
				},400)
			},500);
			hsC=$(this).parent('li').attr('eq');
			if(hsC<hSN_li_Num-1 && hsC>0){
				$(this).parents('ul').stop(true,false).animate({top:hsH*(--hsC)},800);
				
			}
			
			
			return false;
		});	
		if(hSN_li_Num>3){
			$(hSN).append('<a href="Prev" class="hs-navi prev"/><a href="Next" class="hs-navi next"/>');
			$('.hs-navi').click(function(e) {
				$(this).hasClass('next') ? hsC<hsN ? hsC++ : hsC=0 : hsC>0 ? hsC-- : hsC=hsC;
				$(hSN+' > ul').stop(true,false).animate({top:hsH*hsC},800);
				return false;
			});
			$(window).resize(function(e) {
				$(hSN+' > ul').stop(true,false).animate({top:0});
				hsC=0;				
			});
			
		}	
		
		setTimeout(function(){
			$(hSN).after('<div style="position:relative; overflow:hidden; height:0;"><div style="height:500px;" id="HSNpreloader"></div></div>');
			$(hSN+' > ul > li > a').each(function(index, element) {
				$('#HSNpreloader').append('<img src="'+$(this).attr('href')+'/>');
			});
		},1000);
	}
	
	
}

/* ----------------------------------------------------- */
/* EOF */
/* ----------------------------------------------------- */


// init
$(document).ready(function(){
	$('.fancybox').fancybox({padding:10});
	$('.fancybox-media').fancybox({
		openEffect : 'none',
		closeEffect : 'none',
		prevEffect : 'none',
		nextEffect : 'none',
		padding:10,
		arrows : false,
		helpers : {
			media : {},
			buttons : {}
		}
	});
	
	$('#content-wrapper').css('padding-bottom',$('footer').height()+40);
	winWid=$('.container').width();
	switch(winWid){
		case 960: $('body').addClass('desktop');break;
		case 768: $('body').addClass('tablet');break;
		case 420: $('body').addClass('iphone');break;
		case 300: $('body').addClass('mobile');break;
	}
	//$('#content-wrapper').
	$(window).resize(function(e){
		$('#content-wrapper').css('padding-bottom',$('footer').height()+40);
		winWid=$('.container').width();
		switch(winWid){
			case 960: $('body').addClass('desktop').removeClass('tablet').removeClass('iphone').removeClass('iphone');break;
			case 768: $('body').removeClass('desktop').addClass('tablet').removeClass('iphone').removeClass('iphone');break;
			case 420: $('body').removeClass('desktop').removeClass('tablet').addClass('iphone').removeClass('mobile');break;
			case 300: $('body').removeClass('desktop').removeClass('tablet').removeClass('iphone').addClass('mobile');break;
		}
	});
	// js for "Safari Apple browser"
	scaleFixHuck();
	
	$('#main-menu-mobile').change(function(e) {
		window.location = $(this).val();
	});
	
	
	// animate social links
	topLinks('.social_links');
	//animate scroll
	backtop();
	// main menu
	mainMenu('#main-menu');
	// main slider [slider id, autoplay(true/false)]
	mainSlider('#slider',true);
	homeSlider('#home-slider','#home-slider-preview','#home-slider .home-slider-navi');
	
	// recent post list
	listRec('.list_recent li','.rec_fade_context','h5');	
	
	// hover box
	overBg('.over-bg');
	
	// toggle box 
	toggleBox('.toggle-link');
	toggHor();
	
	// testimonials [testimonials list, testimonials navi container, autoplay(true/false)]
	testimonials('#testimonials','#testim_navi', true,1);
	testimonials('#recent-blog','#recent-navi', false,4);
	testimonials('#recent-projects-list','#recent-navi-inner', false,4);
	testimonials('.blog-posts','#blog-navi', false,4);
	
	// tabs 
	tabNavi('.tab-navi');
	closeNote('.close-note','.note')
	
	// accordation 
	accordation('.accordation-items','.accordation-item','.accordation-item-body','.accordation-item-header a');
	toggle('.jToggle-item','.jToggle-item-body','.jToggle-item-header a');

	portfolioDetail('.gallery');
	
	postSlider('.post-image');
	
	// slider slogan 
	slogansLider('#slogan-slider-box');
	
	// description 
	tdDescription('.desc-container');
	// comments 
	
	comments();
});
