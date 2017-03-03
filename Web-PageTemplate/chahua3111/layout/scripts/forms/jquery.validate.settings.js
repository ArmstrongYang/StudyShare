$.validator.setDefaults({
	submitHandler: function() {
		name_j = $('input[name="n-name"]').val();
		email_j = $('input[name="n-email"]').val();	
		subject_j = $('input[name="n-subject"]').val();
		message_j = $('textarea[name="n-mess"]').val();	
		$.post('sendform.php', {name:name_j, email:email_j, subject:subject_j, message:message_j}, function(data)	{
			window.location.reload(true);
			});	
		 //alert("submitted!"); 
	},
	highlight: function(input) {
		$(input).addClass("ui-state-highlight");
	},
	unhighlight: function(input) {
		$(input).removeClass("ui-state-highlight");
	}
});

$().ready(function() {
	$.fn.themeswitcher && $('<div/>').css({
		position: "absolute",
		right: 10,
		top: 10
	}).appendTo(document.body).themeswitcher();
	
	// validate the comment form when it is submitted
	$("#SendContact").validate();
	
	
});